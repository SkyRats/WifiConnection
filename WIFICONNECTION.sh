if   [[ $1 = "install" ]]
then
    sudo apt install net-tools network-manager -y
elif [[ $1 = "make" ]]
then
    ./firstoffall.sh
elif [[ $1 = "start" ]]
then
    ./connection
elif [[ $1 = "stop" ]]
fi