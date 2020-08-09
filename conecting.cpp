#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h>

//Verificacoes iniciais
int preciosismo();

//Criacao da rede wifi com o Network-Manager
int conect();

int main (int argc, char *argv[])
{
  printf("\n----------BORA DEIXAR SUPIMPA!----------\n");
  if(preciosismo())
  {
    printf("Faltou algum pre-requisito.\nVerifique a dependência não encontrada:\n network-manager\n");
    exit(1);
  }
  if(conect())
  {
    printf("Erro ao conectar na rede wifi\n");
    exit(1);
  }
  printf("-->Tudo pronto! \n\nCom carinho,\n  RickLake\n\n");
  return 0;
}

int preciosismo()
{
  printf("\n--> Onde estão as dependências?\n");
  int resp = system("which nmcli");
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

