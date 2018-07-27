#!/bin/bash
if [ $(dpkg-query -W -f='${Status}' virtualbox 2>/dev/null | grep -c "ok installed") -eq 0 ];
    then
        if [ $(apt-cache search virtualbox | grep virtualbox) ];
            then
                apt-get install -y virtualbox
            else
                apt-add-repository "deb http://download.virtualbox.org/virtualbox/debian vivid contrib"
                wget -q https://www.virtualbox.org/download/oracle_vbox.asc -O- | apt-key add -
                apt-get update
                apt-get install -y virtualbox-5.0
        fi
fi
