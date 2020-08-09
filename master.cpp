#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h>


//Verificacoes iniciais
int preciosismo();

//Pega o ip4 do dispositivo wifi
int getIP(char *ip);

//Prepara a master para o ros
void rosMaster(char *ip);

int main (int argc, char *argv[])
{
  char ip[15];
  printf("\n----------BORA DEIXAR SUPIMPA!----------\n");
  if(preciosismo())
  {
    printf("Faltou algum pre-requisito.\nVerifique a dependência não encontrada:\n hostname\n");
    exit(1);
  }
  if(getIP(ip))
  {
    printf("Erro ao pegar esse IP\n");
    exit(1);
  }
  rosMaster(ip);
  printf("-->Tudo pronto! ANOTE esse IP da master e pode dar roscore!\n\nCom carinho,\n  RickLake\n\n");
  return 0;
}

int preciosismo()
{
  printf("\n--> Onde estão as dependências?\n");
  int resp = system("which hostname");
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
  printf("--> O IP encontrado do wifi foi:\n%s (ANOTE)\n\n", ip);
  pclose(answ);
  return 0;
}

void rosMaster(char ip[15])
{
  //char command1[200];
  char command2[200];
  char command3[200];
  //sprintf(command1, "export ROS_HOSTNAME=localhost");
  sprintf(command2, "export ROS_IP=%s", ip);
  sprintf(command3, "export ROS_MASTER_URI=http://%s:11311", ip);
  //system(command1);
  system(command2);
  system(command3);
}


