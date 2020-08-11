#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h>
#include <string.h>

//Verificacoes iniciais
int preciosismo();

//Criacao da rede wifi com o Network-Manager
int conect();

//Pega o ip4 do dispositivo wifi
int getIP(char *ip);


int main (int argc, char *argv[])
{
  char ip[15];
  printf("\n----------BORA DEIXAR SUPIMPA!----------\n");
  if(preciosismo())
  {
    printf("Faltou algum pre-requisito.\nVerifique as dependência não encontradas dentre:\n hostname ros network-manager\n");
    exit(1);
  }
  if(conect())
  {
    printf("Erro ao conectar na rede wifi\n");
    exit(1);
  }
  if(getIP(ip))
  {
    printf("Erro ao pegar o IP dessa maquina\n");
    exit(1);
  }
  printf("-->Tudo pronto! ANOTE esse IP!\n\nCom carinho,\n  RickLake\n\n");
  return 0;
}

int preciosismo()
{
  printf("\n--> Onde estão as dependências?\n");
  int resp = system("which roscore hostname nmcli");
  if (resp == 0)
  {
    printf("Dependencias encontradas!\n\n");
    system("nmcli networking on");
    system("nmcli radio wifi on");
    return 0;
  }
  return 1;
}

int conect()
{
  if(system("nmcli device wifi connect HotDaSky password 1234567891234"))
  {
    return 1;
  }
  return 0;
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

