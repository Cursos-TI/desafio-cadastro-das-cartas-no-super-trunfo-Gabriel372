#include <stdio.h>
#include <string.h>

int main() {
//declaracao das variaveis
char codigo[20], nome[20];
int populacao;
float area,PIB;
int numeroDePontosTuristicos ;
//intercao com  o usuario
printf("Digite o codigo da cidade:\n");
scanf("%19s",codigo);
    getchar();
printf("Digite o nome da cidade:\n");
fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0';
printf("Digite a quantidade da populacao:\n");
scanf("%d",&populacao);
printf("Digite a dimensao da area em km2:\n");
scanf("%f",&area);
printf("Digite o valor do PIB:\n");
scanf("%f",&PIB);
printf("Digite a quantidade de pontos turisticos:\n");
scanf("%d",&numeroDePontosTuristicos);
//resultado da interacao
printf("==================CARTA CADASTRADA!=========\n");
printf("Codigo da cidade:%s\n",codigo);
printf("Nome da cidade:%s\n",nome);
printf("Quantidade da populacao:%d\n",populacao);
printf("Dimensao da area:%.1f km2\n",area);
printf("PIB:%.1f R$\n",PIB);
printf("Quantidade de pontos turisticos:%d\n",numeroDePontosTuristicos);
return 0;
}
