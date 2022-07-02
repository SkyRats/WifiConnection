#!/bin/bash

cd /home/caninos/WifiConnection

#Generating connection binary file
source firstofall.sh

#moving the connect.sh target script
sudo mv connect.sh /usr/local/bin/connect.sh
sudo chmod 744 /usr/local/bin/connect.sh

#moving the skyratshotspot-connect.service systemd service
sudo mv skyratshotspot-connect.service /etc/systemd/system/skyratshotspot-connect.service
sudo chmod 664 /etc/systemd/system/skyratshotspot-connect.service

#reloading the daemon and enabling the service
sudo systemctl daemon-reload
sudo systemctl enable skyratshotspot-connect.service

echo "Se nenhum erro apareceu, basta rebootar a labrador e ela deve conectar com o hotspot automaticamente"
