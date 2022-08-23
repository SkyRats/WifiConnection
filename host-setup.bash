#!/bin/bash

#Installing dependencies
sudo apt install net-tools network-manager -y

#Generating connection binary file
source build.sh

#Hosting for the first time
./newhotspot

echo "Se nenhum erro apareceu, um hotspot deve ter sido criado, note que ele nao sera criado por padrao quando o computador ligar, leia o README para mais informacoes"
echo "Ass: Fuco"