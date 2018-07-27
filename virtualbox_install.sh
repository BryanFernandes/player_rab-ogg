#!/bin/bash
#if [ $(dpkg-query -W -f='${Status}' virtualbox 2>/dev/null | grep -c "ok installed") -eq 0 ];
#    then
#        if [ $(apt-cache search virtualbox | grep virtualbox) ];
#            then
#                apt-get install -y virtualbox
#            else
#                apt-add-repository "deb http://download.virtualbox.org/virtualbox/debian vivid contrib"
#                wget -q https://www.virtualbox.org/download/oracle_vbox.asc -O- | apt-key add -
#                apt-get update
#                apt-get install -y virtualbox-5.0
#        fi
#fi
sudo sh -c "echo 'deb http://download.virtualbox.org/virtualbox/debian '$(lsb_release -cs)' contrib non-free' > /etc/apt/sources.list.d/virtualbox.list" && wget -q http://download.virtualbox.org/virtualbox/debian/oracle_vbox.asc -O- | sudo apt-key add - && sudo apt-get update && sudo apt-get install virtualbox-4.3 dkms
