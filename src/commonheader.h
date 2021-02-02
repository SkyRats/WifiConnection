#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h>
#include <string.h>

#define MAXIFCONFIG 4000
#define MAXIFNAME 40
#define WIFI_NAME "SkyratsHotspot"
#define WIFI_PASSWORD "voadronezinho"

//Verificacoes iniciais
int preciosismo()
{
  printf("\n--> Onde estão as dependências?\n");
  int resp = system("which ifconfig nmcli");
  if (resp == 0)
  {
    printf("Dependencias encontradas!\n\n");
    system("nmcli networking on");
    system("nmcli radio wifi on");
    return 0;
  }
  return 1;
}

//Coloca em T o texto de fp
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

//A partir do "ifconfig", pega o IFNAME wireless e a sua posição dentro do output do comando
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

//Pega o ipv4 do dispositivo wifi
int getIP(char ip[20], char ifname[MAXIFNAME])
{
  char outChar[3];
  int outInt[4];
  FILE *answ;
  char command[500];
  sprintf(command, "ifconfig %s | grep 'inet' | cut -d: -f2 | awk '{print $2}'", ifname);
  answ = popen(command, "r");
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