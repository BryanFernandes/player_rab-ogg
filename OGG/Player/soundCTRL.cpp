#include "soundCTRL.h"

SoundCTRL *g_control = 0;

SoundCTRL::SoundCTRL()
{
	playing = 1;
	view = 0;
	sound = 0;
	
	timeInSeconds = 0;

	g_control = this;
}

void
SoundCTRL::setSound(Sound *sound)
{
	this->sound = sound;
}

void
SoundCTRL::setView(Ui_meta *view)
{
	this->view = view;
	connect(view, SIGNAL(playSound()), this, SLOT(playOrPauseCTRL()));
	connect(view, SIGNAL(pauseSound()), this, SLOT(playOrPauseCTRL()));
	
	connect(this, SIGNAL(soundPlayed()), this->view, SLOT(playOrPause()));
	connect(this, SIGNAL(soundPlayed()), this->view, SLOT(resetClockAndSlider()));
	
	connect(this, SIGNAL(changeAllMarks()), this->view, SLOT(changeMarksLabels()));

	connect(view, SIGNAL(nextMark(uint32_t, Format*)), this, SLOT(forward(uint32_t, Format*)));
	connect(view, SIGNAL(prevMark(uint32_t, Format*)), this, SLOT(rewind(uint32_t, Format*)));
	
	connect(view, SIGNAL(forwardTime(Format *)), this, SLOT(fastForward(Format *)));
	connect(view, SIGNAL(rewindTime(Format *)), this, SLOT(fastRewind(Format *)));
	
	connect(this, SIGNAL(clock(int)), this->view, SLOT(updateClock(int)));
	
	connect(view, SIGNAL(update_m_position(uint32_t, Format*)), this, SLOT(set_m_position(uint32_t, Format*)));
	
}

void 
SoundCTRL::playOrPauseCTRL()
{
	//cout << "[Toca ou para] playing = " << playing << endl;

	fprintf(stderr, " IN: soundCTRL.cpp -> playOrPauseCTRL\n");

	if (sound->m_position == -1)
		sound->m_position = 0;

	playing ^= 1;
	SDL_PauseAudio(playing);

	fprintf(stderr, " OUT: soundCTRL.cpp -> playOrPauseCTRL\n");
}

void 
SoundCTRL::callback(void *userdata, uint8_t *audio, int length)
{
	//fprintf(stderr, " IN: soundCTRL.cpp -> callback\n");
	memset(audio, 0, length);

	//fprintf(stderr, " soundCTRL.cpp VARIABLE VALUE in callback: length: %d\n", length);
	
	Sound *sound = (Sound *) userdata;

	//fprintf(stderr, " soundCTRL.cpp VARIABLE VALUE in callback: sound->size(): %d\n", sound->size());

	if (sound->m_position == -1)
		return;

	if (sound->m_position >= sound->size())
	{
		//cout << "-----------------------------" << endl;
		cout << "ACABOU...A MUSICA!!!" << endl;

		sound->m_position = -1;

		emit g_control->soundPlayed();
		
		return;
	}

	int nextSamplesLength;

	if (sound->m_position + length > sound->size())
		nextSamplesLength =  sound->size() - sound->m_position;
	else
		nextSamplesLength = length;

	SDL_MixAudio(audio, sound->buffer() + sound->m_position, nextSamplesLength, 
		SDL_MIX_MAXVOLUME / 2);

	sound->m_position += nextSamplesLength;

    g_control->changeLabels();
	
	//fprintf(stderr, " OUT: soundCTRL.cpp -> callback\n");
}

void 
SoundCTRL::fastForward(Format *format)
{
	//cout << "AVANCEI!!"<< endl;
	if(sound->m_position <= 0)
	{
		sound->m_position = 0;
	}
	else
	{
		uint32_t position = 5 * format->numChannels() * format->sampleRate() * format->bitsPerSample()/8;
		sound->m_position += position;
	}
}
	
void 
SoundCTRL::fastRewind(Format *format)
{
	//cout << "VOLTEI!!"<< endl;
	
	//cout << "sound->m_position: " << sound->m_position << endl;
	
	//pra evitar falha de segmentação
	if(sound->m_position <= 0 || sound->m_position <= (int)(5 * format->numChannels() * format->sampleRate() * format->bitsPerSample()/8))
	{
		sound->m_position = 0;
	}
	else
	{
		uint32_t position = 5 * format->numChannels() * format->sampleRate() * format->bitsPerSample()/8;
		sound->m_position -= position;
	}
}

void 
SoundCTRL::rewind(uint32_t timeInSeconds, Format *format)
{
	//cout << "rewind control: " << timeInSeconds << endl;
	uint32_t position = timeInSeconds * format->numChannels() * format->sampleRate() * format->bitsPerSample()/8;
	
	sound->m_position = position;
}

void 
SoundCTRL::forward(uint32_t timeInSeconds, Format *format)
{
    fprintf(stderr, "\n\n\t ****** foward control: %u\n", timeInSeconds);
	fprintf(stderr, "\t ****** number channels: %hu\n", format->numChannels());
    fprintf(stderr, "\t ****** sample rate: %u\n", format->sampleRate());
    fprintf(stderr, "\t ****** bits per sample: %hu\n", format->bitsPerSample());
    //cout << "forward control: " << timeInSeconds << endl;
	uint32_t position = timeInSeconds * format->numChannels() * format->sampleRate() * format->bitsPerSample()/8;
	
	//cout << "position: " << position << endl; 
	
	sound->m_position = position;
}

void 
SoundCTRL::set_m_position(uint32_t timeInSeconds, Format *format)
{
	uint32_t position = timeInSeconds * format->numChannels() * format->sampleRate() * format->bitsPerSample()/8;
	sound->m_position = position;
}

uint32_t update_mark(const vector<uint32_t>& marks, int timeInSeconds)
{
	
	for (int i = 1; i < (int) marks.size(); i++)
	{
		if ((int) marks[i] > timeInSeconds)
			return i - 1;
	}
	
	return marks.size() - 1;
}

void
SoundCTRL::changeLabels()
{
	timeInSeconds = (8 * sound->m_position)/(view->getFormat()->numChannels() * view->getFormat()->sampleRate() * view->getFormat()->bitsPerSample());
	
	int nextMark = view->MarkIndex();
	int nextSubMark = view->SubMarkIndex();

	vector<uint32_t> marks = view->marks();
	vector<uint32_t> subMarks = view->subMarks();

	/*cout << "Subs = [";
	for (int i = 0; i < (int )subMarks.size(); i++)
		cout << subMarks[i] << " ";
	cout << "]" << endl;
	*/
	uint32_t now = update_mark(marks, timeInSeconds);
	//cout << "timeInSeconds: " << timeInSeconds << ", nextMark: "<< nextMark<< "," << "nextSubMark: "<< nextSubMark << ", now = " << now << endl;
	
	if (now != (uint32_t) nextMark)
	{
		view->setMarkIndex(now);
	}

	now = update_mark(subMarks, timeInSeconds);

	//cout << "Novo now = " << now << endl;
	
	if (now != (uint32_t) nextSubMark)
	{
		view->setSubMarkIndex(now);	
	}
	
	emit changeAllMarks();
	emit clock((int) timeInSeconds);
}









