#include "commonheader.h"

//Coneccao da rede wifi pelo NetworkManager
int connect();

int main (int argc, char *argv[])
{
  char ifname[MAXIFNAME], ip[15];
  printf("\n----------BORA DEIXAR SUPIMPA!----------\n");
  if(preciosismo())
  {
    printf("Faltou algum pre-requisito.\nVerifique a dependência não encontrada dentre:\nifconfig, network-manager\n");
    exit(1);
  }
  if(getIfname(ifname))
  {
    printf("Erro ao pegar ifname\n");
    exit(1);
  }
  if(connect())
  {
    printf("Erro ao conectar na rede wifi\n");
    exit(1);
  }
  if(getIP(ip, ifname))
  {
    printf("Erro ao pegar o IP dessa maquina\n");
    exit(1);
  }
  printf("--> Tudo pronto! ANOTE esse IP!\n\nCom carinho,\n  RickLake\n\n");
  return 0;
}

int connect()
{ 
  char command[100];
  sprintf(command, "nmcli device wifi connect %s password %s", WIFI_NAME, WIFI_PASSWORD);
  if(system(command))
  {
    return 1;
  }
  return 0;
}

