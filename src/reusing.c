#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h>

#include "defines.h"

//Verificacoes iniciais
void preciosismo();

//Criacao da rede wifi com o Network-Manager
int turnOnHotspot();

//Pega o ip4 do dispositivo wifi
int getIP(char *ip);

int main (int argc, char *argv[])
{
  char ifname[MAXIFNAME], ip[15];
  printf("\n----------BORA DEIXAR SUPIMPA!----------\n");

  preciosismo();

  if(turnOnHotspot())
  {
    printf("Erro ao criar o hotspot\n");
    exit(1);
  }
  if(getIP(ip))
  {
    printf("Erro ao pegar esse IP\n");
    exit(1);
  }
  printf("-->Tudo pronto! ANOTE esse IP!\n\nCom carinho,\n  RickLake\n\n");
  return 0;
}

void preciosismo()
{
  system("nmcli networking on");
  system("nmcli radio wifi on");
}

int turnOnHotspot()
{
  char command[500];
  sprintf(command, "nmcli connection up ip %s", WIFI_NAME);
  if(system(command))
  {
    return 1;
  }
  printf("\n--> UHULL: Ligada a rede wifi '%s' com senha '%s'\n\n", WIFI_NAME, WIFI_PASSWORD);
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
  printf("--> O IP encontrado do wifi foi:\n%s (ANOTE)\n\n", ip);
  pclose(answ);
  return 0;
}


