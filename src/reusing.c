#include "commonheader.h"

//Criacao da rede wifi com o Network-Manager
int turnOnHotspot();

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
  if(turnOnHotspot())
  {
    printf("Erro ao criar o hotspot\n");
    exit(1);
  }
  if(getIP(ip, ifname))
  {
    printf("Erro ao pegar esse IP\n");
    exit(1);
  }
  printf("--> Tudo pronto! ANOTE esse IP!\n\nCom carinho,\n  RickLake\n\n");
  return 0;
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
