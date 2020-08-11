#não coloquei um interpretador pois eh para rodar soh em terminal
# #! /bin/bash
printf '\n----------BORA DEIXAR SUPIMPA!----------\n\v'

IP=`hostname -I | awk '{print $1}'`
printf "\--> O IP do wifi desse computador:\n %s \n\v" "$IP"

EXP1=`printf "ROS_HOSTNAME=%s" "$IP"`
EXP2=`printf 'ROS_IP=%s' "$IP"`
EXP3=`printf 'ROS_MASTER_URI=http://%s:11311' "$IP"`

export "$EXP1"
#echo "EXP1: $EXP1"
export "$EXP2"
#echo "EXP2: $EXP2"
export "$EXP3"
#echo "EXP3: $EXP3"

printf '\--> Tudo pronto! Agora pode rodar o que quiser do ros nesse terminal!\n (Inclusive o roscore...)\n\vCom carinho,\n  RickLake\n\v'

#Descomente essa ultima linha caso queira executar no terminal sem source
#/bin/bash

