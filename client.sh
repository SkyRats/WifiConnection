#não coloquei um interpretador pois eh para rodar soh em terminal
# #! /bin/bash
if [ -z $1 ]
then
    printf "Por favor, coloque como argumento do programa o IP4 da master!\n (Assim olha: source client.sh [ip_master])\n"
    
else
    printf '\n----------BORA DEIXAR SUPIMPA!----------\n\v'

    IP=`hostname -I | awk '{print $1}'`
    printf "\--> O IP do wifi desse computador:\n %s \n\v" "$IP"

    IP2="$1"
    printf "\--> O IP da master (que voce digitou):\n %s\n\v" "$IP2"

    EXP1=`printf "ROS_HOSTNAME=%s" "$IP"`
    EXP2=`printf 'ROS_IP=%s' "$IP"`
    EXP3=`printf 'ROS_MASTER_URI=http://%s:11311' "$IP2"`

    export "$EXP1"
    #echo "EXP1: $EXP1"
    export "$EXP2"
    #echo "EXP2: $EXP2"
    export "$EXP3"
    #echo "EXP3: $EXP3"

    printf '\--> Tudo pronto! Agora pode rodar o que quiser do ros nesse terminal!\n (Lembrando que não precisa de roscore nesse computador...)\n\vCom carinho,\n  RickLake\n\v'

    #Descomente essa ultima linha caso queira executar no terminal sem source
    #/bin/bash
fi

