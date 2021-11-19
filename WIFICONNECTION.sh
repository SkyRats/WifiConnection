if   [[ $1 = "install" ]]
then
    sudo apt install net-tools network-manager -y
elif [[ $1 = "make" ]]
then
    source firstoffall.sh
elif [[ $1 = "start" ]]
then
    echo "Ligando..."
    ./newhotspot
    ./connection
elif [[ $1 = "stop" ]]
then
    echo "Desligando..."
    nmcli connection down SkyratsHotspot
fi