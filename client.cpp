#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h>
#include <string.h>


//Verificacoes iniciais
int preciosismo();

//Pega o ip4 do dispositivo wifi
int getIP(char *ip);

//Prepara a master para o ros
void rosMaster(char *ip, char *ip2);

int main (int argc, char *argv[])
{
  char ip[15], ip2[15];
  if (argc != 2)
  {
    printf("Por favor, coloque como argumento do programa o IP4 da master!\n(Assim olha:[exec] [ip_master])\n");
    return 1;
  }
  strcpy(ip2, argv[1]);
  printf("\n----------BORA DEIXAR SUPIMPA!----------\n");
  if(preciosismo())
  {
    printf("Faltou algum pre-requisito.\nVerifique as dependência não encontradas dentre:\n hostname ros\n");
    exit(1);
  }
  if(getIP(ip))
  {
    printf("Erro ao pegar o IP dessa máquina\n");
    exit(1);
  }
  printf("--> O IP da master (que voce digitou):\n%s\n\n", ip2);
  rosMaster(ip, ip2);
  printf("-->Tudo pronto! N precisa dar roscore aqui. \n\nCom carinho,\n  RickLake\n\n");
  return 0;
}

int preciosismo()
{
  printf("\n--> Onde estão as dependências?\n");
  int resp = system("which roscore hostname");
  if (resp == 0)
  {
    printf("Dependencias encontradas!\n\n");
    return 0;
  }
  return 1;
}

int getIP(char ip[20])
{
  char outChar[3];
  int outInt[4];
  FILE *answ;
  answ = popen("hostname -I | awk '{print $1}'", "r");
  if (answ == NULL)
  {
    printf("Erro no popen(\"ifconfig\")\n");
    return 1;
  }
  fscanf(answ, "%d", &outInt[0]);
  fscanf(answ, "%c", &outChar[0]);
  fscanf(answ, "%d", &outInt[1]);
  fscanf(answ, "%c", &outChar[1]);
  fscanf(answ, "%d", &outInt[2]);
  fscanf(answ, "%c", &outChar[2]);
  fscanf(answ, "%d", &outInt[3]);
  sprintf(ip, "%d%c%d%c%d%c%d", outInt[0], outChar[0], outInt[1], outChar[1], outInt[2], outChar[2], outInt[3]);
  printf("--> O IP do wifi desse computador:\n%s\n\n", ip);
  pclose(answ);
  return 0;
}

void rosMaster(char ip[15], char ip2[15])
{
  //char command1[200];
  char command2[200];
  char command3[200];
  //sprintf(command1, "export ROS_HOSTNAME=localhost");
  sprintf(command2, "export ROS_IP=%s", ip);
  sprintf(command3, "export ROS_MASTER_URI=http://%s:11311", ip2);
  //system(command1);
  system(command2);
  system(command3);
}


