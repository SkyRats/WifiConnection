#!/bin/bash

#Installing dependencies
sudo apt install net-tools network-manager -y

#Generating connection binary file
source build.sh

#Hosting for the first time
./newhotspot

echo "Se nenhum erro apareceu, basta rebootar a sbc e ela deve conectar com o hotspot automaticamente"
echo "Ass: Fuco"