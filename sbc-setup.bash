#!/bin/bash

#Installing dependencies
sudo apt install net-tools network-manager -y

#Generating connection binary file
source build.sh

#Connection for the first time
echo "---Para essa etapa, certifique-se que o hotspot esta ligado no seu computador pessoal!---"
./connection

#Setting connection priority
nmcli connection modify SkyratsHotspot connection.autoconnect-priority 10

echo "Se nenhum erro apareceu, basta rebootar a sbc e ela deve conectar com o hotspot automaticamente sempre que ele estiver disponivel"
echo "Ass: Fuco"
