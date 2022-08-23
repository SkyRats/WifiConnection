#!/bin/bash

if [[ $1 = "start" ]]
then
    echo "Ligando..."
    ./newhotspot
elif [[ $1 = "stop" ]]
then
    echo "Desligando..."
    nmcli connection down SkyratsHotspot
fi
