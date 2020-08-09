#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h>

#define MAXIFCONFIG 4000
#define MAXIFNAME 40

//Verificacoes iniciais
int preciosismo();

//Coloca em T o texto de fp
int leTexto (FILE *fp , char T[MAXIFCONFIG]);

//A partir do "ifconfig", pega o IFNAME wireless e a sua posição dentro do output do comando
int getIfname(char *ifname);

//Criacao da rede wifi com o Network-Manager
int makeHotspot(char *ifname);

//Pega o ip4 do dispositivo wifi
int getIP(char *ip);

//Prepara a master para o ros
void rosMaster(char *ip);

int main (int argc, char *argv[])
{
  char ifname[MAXIFNAME], ip[15];
  printf("\n----------BORA DEIXAR SUPIMPA!----------\n");
  if(preciosismo())
  {
    printf("Faltou algum pre-requisito.\nVerifique a dependência não encontrada dentre:\nifconfig, network-manager, hostname\n");
    exit(1);
  }
  if(getIfname(ifname))
  {
    printf("Erro ao pegar ifname\n");
    exit(1);
  }
  if(makeHotspot(ifname))
  {
    printf("Erro ao criar o hotspot\n");
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
  int resp = system("which ifconfig nmcli hostname");
  if (resp == 0)
  {
    printf("Dependencias encontradas!\n\n");
    system("nmcli networking on");
    system("nmcli radio wifi on");
    return 0;
  }
  return 1;
}

int leTexto (FILE *fp , char T[MAXIFCONFIG])
{
  int r = 0, k = 0;
  for (k = 0; k < MAXIFCONFIG && (r = fscanf (fp, "%c", &T[k])) > 0; ++k);
  if(r<=0)
  {
    T[k] = '\0';
    return 0;
  }
  printf("MAXIFCONFIG eh insuficiente (saida de ifconfig muito grande)\n");
  fclose(fp);
  return 1;
}

int getIfname(char ifname[MAXIFNAME])
{
  char output[MAXIFCONFIG];
  int j, i;
  FILE *answ;
  answ = popen("ifconfig", "r");
  if (answ == NULL)
  {
    printf("Erro no popen(\"ifconfig\")\n");
    return 1;
  }
  if (leTexto(answ, output))
  {
    return 1;
  }
  for(i = 0; !(output[i] == '\n' && output[i+1] == 'w') && output[i] != 0; ++i);
  if(output[i] == 0)
  {
    printf("Não ha dispositivo wireless\n");
    return 1;
  }
  ++i;
  for(j = 0; output[i + j] != ' '; j++)
  {
    ifname[j] = output[i + j];
  }
  ifname[j-1] = 0;
  printf("--> O dispositivo wifi encontrado foi o %s\n", ifname);
  pclose(answ);
  return 0;
}

int makeHotspot(char ifname[MAXIFNAME])
{
  char command[200];
  sprintf(command, "nmcli device wifi hotspot ifname %s con-name HotDaSky ssid HotDaSky password 1234567891234", ifname);
  if(system(command))
  {
    return 1;
  }
  printf("\n--> UHULL: Criada a rede 'HotDaSky' com senha '1234567891234'\n\n");
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


