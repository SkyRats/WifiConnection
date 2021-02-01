#! /bin/bash

if [ -z $1 ]
then
    echo "-->Por favor digite o ifname (ex: wlp2s0, wlan0...) no primeiro argumento"
    exit
fi

IFNAME=$1

nmcli device wifi hotspot ifname $IFNAME con-name HotDaSky ssid HotDaSky password 1234567891234

echo ""
echo "--> UHULL: Criada a rede 'HotDaSky' com senha '1234567891234'"
echo ""

