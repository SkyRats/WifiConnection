#!/bin/bash

#Generating connection binary file
source build.sh

#Connection for the first time
echo "---Para essa etapa, certifique-se que o hotspot esta ligado no seu computador pessoal!---"
./connection

#Setting connection priority
nmcli connection modify SkyratsHotspot connection.autoconnect-priority 10

echo "Se nenhum erro apareceu, basta rebootar a labrador e ela deve conectar com o hotspot automaticamente"
echo "Ass: Fuco"
