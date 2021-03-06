/*  QtSpeech -- a small cross-platform library to use TTS
    Copyright (C) 2010-2011 LynxLine.

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 3 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General
    Public License along with this library; if not, write to the
    Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
    Boston, MA 02110-1301 USA */

#include <QtCore>
#include <QtSpeech>

#define WINVER 0x0500 // At least WinXP required
#include <windows.h>
#include "sapi.hh"
#include "sphelper.hh"

using std::wstring;

namespace QtSpeech_v1 { // API v1.0

// some defines for throwing exceptions
#define Where QString("%1:%2:").arg(__FILE__).arg(__LINE__)
#define SysCall(x,e) {                                          \
    HRESULT hr = x;                                             \
    if (FAILED(hr)) {                                           \
        QString msg = QString("%1:%2:%3:%4:error code %5")      \
                  .arg(#e)                                      \
                  .arg(__FILE__)                                \
                  .arg(__LINE__)                                \
                  .arg(#x)                                      \
                  .arg(hr, 0, 16);                              \
        throw e(msg);                                           \
    }                                                           \
}

// internal data
class QtSpeech::Private {
public:
    Private()
        : waitingFinish(false) {}

    VoiceName name;

    static const QString VoiceId;
    typedef QPointer<QtSpeech> Ptr;
    static QList<Ptr> ptrs;  // Useless?

    ISpVoice * voice;

    bool waitingFinish;
    class WCHAR_Holder {
    public:
        WCHAR * w;
        WCHAR_Holder(QString s)
            :w(0) {
            w = new WCHAR[s.length()+1];
            s.toWCharArray(w);
            w[s.length()] =0;
        }

        ~WCHAR_Holder() { delete[] w; }
    };
};
const QString QtSpeech::Private::VoiceId = QString("win:%1");
QList<QtSpeech::Private::Ptr> QtSpeech::Private::ptrs = QList<QtSpeech::Private::Ptr>();

// implementation
QtSpeech::QtSpeech(QObject * parent)
    :QObject(parent), d(new Private)
{
    // FIXME no CoUninitialize()
    CoInitialize(NULL);
    SysCall( CoCreateInstance(CLSID_SpVoice, NULL, CLSCTX_INPROC_SERVER, IID_ISpVoice,
                              (void**)&d->voice), InitError);

    VoiceName n;
    WCHAR * w_id = 0L;
    WCHAR * w_name = 0L;
    ISpObjectToken * voice;
    SysCall( d->voice->GetVoice(&voice), InitError);
    SysCall( SpGetDescription(voice, &w_name), InitError);
    SysCall( voice->GetId(&w_id), InitError);
    n.name = QString::fromWCharArray(w_name);
    n.id = QString::fromWCharArray(w_id);
    voice->Release();

    if (n.id.isEmpty())
        throw InitError(Where+"No default voice in system");

    d->name = n;
    d->ptrs << this;
}

QtSpeech::QtSpeech(VoiceName n, QObject * parent)
    :QObject(parent), d(new Private)
{
    ULONG count = 0;
    IEnumSpObjectTokens * voices;

    // FIXME no CoUninitialize()
    CoInitialize(NULL);
    SysCall( CoCreateInstance(CLSID_SpVoice, NULL, CLSCTX_INPROC_SERVER, IID_ISpVoice,
                              (void**)&d->voice), InitError);

    if (n.id.isEmpty()) {
        WCHAR * w_id = 0L;
        WCHAR * w_name = 0L;
        ISpObjectToken * voice;

        SysCall( d->voice->GetVoice(&voice), InitError);
        SysCall( SpGetDescription(voice, &w_name), InitError);
        SysCall( voice->GetId(&w_id), InitError);
        n.name = QString::fromWCharArray(w_name);
        n.id = QString::fromWCharArray(w_id);
        voice->Release();
    }
    else {
        SysCall( SpEnumTokens(SPCAT_VOICES, NULL, NULL, &voices), InitError);
        SysCall( voices->GetCount(&count), InitError);
        for (ULONG i =0; i< count; i++) {
            WCHAR * w_id = 0L;
            ISpObjectToken * voice;
            SysCall( voices->Next( 1, &voice, NULL ), InitError);
            SysCall( voice->GetId(&w_id), InitError);
            QString id = QString::fromWCharArray(w_id);
            if (id == n.id) d->voice->SetVoice(voice);
            voice->Release();
        }
    }

    if (n.id.isEmpty())
        throw InitError(Where+"No default voice in system");

    d->name = n;
    d->ptrs << this;
}

QtSpeech::~QtSpeech()
{
    d->ptrs.removeAll(this);
    delete d;
}

const QtSpeech::VoiceName & QtSpeech::name() const {
    return d->name;
}

QtSpeech::VoiceNames QtSpeech::voices()
{
    VoiceNames vs;       
    ULONG count = 0;
    IEnumSpObjectTokens * voices;

    CoInitialize(NULL);
    SysCall( SpEnumTokens(SPCAT_VOICES, NULL, NULL, &voices), LogicError);
    SysCall( voices->GetCount(&count), LogicError);

    for(ULONG i=0; i< count; i++) {
        WCHAR * w_id = 0L;
        WCHAR * w_name = 0L;
        ISpObjectToken * voice;
        SysCall( voices->Next( 1, &voice, NULL ), LogicError);
        SysCall( SpGetDescription(voice, &w_name), LogicError);
        SysCall( voice->GetId(&w_id), LogicError);

        QString id = QString::fromWCharArray(w_id);
        QString name = QString::fromWCharArray(w_name);
        VoiceName n = { id, name };
        vs << n;

        voice->Release();
    }
    return vs;
}

void QtSpeech::tell(QString text)
{
    if (d->waitingFinish)
        SysCall( d->voice->Speak( 0, SPF_PURGEBEFORESPEAK, 0), LogicError);

    d->waitingFinish = true;
    startTimer(100);

    Private::WCHAR_Holder w_text(text);
    SysCall( d->voice->Speak( w_text.w, SPF_ASYNC | SPF_IS_NOT_XML, 0), LogicError);
}

void QtSpeech::say(QString text)
{
    Private::WCHAR_Holder w_text(text);
    SysCall( d->voice->Speak( w_text.w, SPF_IS_NOT_XML, 0), LogicError);
}

void QtSpeech::timerEvent(QTimerEvent * te)
{
    QObject::timerEvent(te);

    if (d->waitingFinish) {
        SPVOICESTATUS es;
        d->voice->GetStatus( &es, NULL );
        if (es.dwRunningState == SPRS_DONE) {
            d->waitingFinish = false;
            killTimer(te->timerId());
            emit finished();
        }
    }
}

} // namespace QtSpeech_v1
