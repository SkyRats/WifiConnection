if   [[ $1 = "install" ]]
then
    sudo apt install net-tools network-manager -y
elif [[ $1 = "make" ]]
then
    ./firstoffall.sh
elif [[ $1 = "start" ]]
then
    echo "Ligando..."
    ./connection
elif [[ $1 = "stop" ]]
then
    echo "Desligando..."
fi