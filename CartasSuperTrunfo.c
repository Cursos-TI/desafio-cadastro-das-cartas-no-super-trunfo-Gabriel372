#include <stdio.h>
#include <string.h>
#include <stdlib.h> 

struct Carta {
    char state[100];
    char code[100];
    char name[100];
    int population;
    float Area;
    float Pib ;
    int numOfPointTouristic;
};
int stringEnumero(char string[100]);
int dadosSaoValidos(struct Carta *carta);
void iniciar();

int stringEnumero(char string[100]) { 
    if (string[0] == '\0') return 0;
    for (int i = 0; string[i] != '\0'; i++) {
        if (string[i] < '0' || string[i] > '9') {
            return 0;
        }
     return 1;//retorna true se a string tiver numeros de 0 a 9
    }
    return 1;
}

void capturarDados(struct Carta ListaDeCartas[2]) {
            struct Carta carta;
    for (int i = 0; i < 2 ; i++)
    { printf("Vamos cadastrar a %da carta \n",i + 1);
if (dadosSaoValidos(&carta)) ListaDeCartas[i] = carta;//se dados estiverem corretos serao inseridos noa array
}
}

int dadosSaoValidos(struct Carta *carta){
 char string[100];
    do
     {
    printf("Digite o nome da cidade:\n");
    fgets(carta->name, sizeof(carta->name), stdin);
    carta->name[strcspn(carta->name, "\n")] = '\0';
if (stringEnumero(carta->name)) printf("Erro: foi digitado um numero.\n");
} while (carta->name[0] == '\0' || stringEnumero(carta->name));
    do
    {
    printf("Digite o nome do estado:\n");
    fgets(carta->state, sizeof(carta->state), stdin);
    carta->state[strcspn(carta->state, "\n")] = '\0';
if (stringEnumero(carta->state)) printf("Erro: foi digitado um numero.\n");
} while (carta->state[0] == '\0' || stringEnumero(carta->state));
    do
    {
    printf("Digite o codigo da carta:\n");
    fgets(carta->code, sizeof(carta->code), stdin);
    carta->code[strcspn(carta->code, "\n")] = '\0';
} while (carta->code[0] == '\0');
 do
  {
    printf("Digite a quantidade da populacao:\n");
    fgets(string, sizeof(string), stdin);
    if (!stringEnumero(string) ) printf("Erro: nao foi digitado um numero.\n");
    carta->population = atoi(string); //converte string p/ numero
    } while (!stringEnumero(string));
 do
  {
    printf("Digite a dimensao da area em km2:\n");
    fgets(string, sizeof(string), stdin);
    if (!stringEnumero(string) ) printf("Erro: nao foi digitado um numero.\n");
    carta->Area = atoi(string);
    } while (!stringEnumero(string));
 do
  {
    printf("Digite o valor do PIB:\n");
    fgets(string, sizeof(string), stdin);
    if (!stringEnumero(string) ) printf("Erro: nao foi digitado um numero.\n");
    carta->Pib = atoi(string);
    } while (!stringEnumero(string));
 do
  {
    printf("Digite a quantidade de pontos turisticos:\n");
    fgets(string, sizeof(string), stdin);
    if (!stringEnumero(string) ) printf("Erro: nao foi digitado um numero.\n");
    carta->numOfPointTouristic = atoi(string);
    } while (!stringEnumero(string));
        return 1;
}

void definirCartaVencedora(struct Carta ListaDeCartas[2]) {
    printf("=========================================\n");
    printf("Comparacao de cartas (Atributo: Area):\n");
    int indexVencedora = (ListaDeCartas[0].Area > ListaDeCartas[1].Area) ? 0 : 1;
    printf("Carta 1 - %s: %.2f\n", ListaDeCartas[0].name, ListaDeCartas[0].Area);
    printf("Carta 2 - %s: %.2f\n", ListaDeCartas[1].name, ListaDeCartas[1].Area);
    if (ListaDeCartas[0].Area == ListaDeCartas[1].Area)
    {
    printf("Deu empate!!\n");
    return;
    }
    printf("Resultado: Carta %d (%s) venceu !\n",indexVencedora + 1,ListaDeCartas[indexVencedora].name);
    printf("\n");
}

void exibirDados(struct Carta ListaDeCartas[2]){
printf("================== CARTAS CADASTRADAS =========\n");
        for (int i = 0; i < 2 ; i++)
{
printf("Carta %d\n", i + 1);
printf("Nome da cidade:%s\n", ListaDeCartas[i].name);
printf("Estado da cidade:%s\n", ListaDeCartas[i].state);
printf("Codigo da cidade:%s\n", ListaDeCartas[i].code);
printf("Quantidade da populacao:%d\n", ListaDeCartas[i].population);
printf("Dimensao da area:%.1f km2\n", ListaDeCartas[i].Area);
printf("PIB:R$ %.1f \n", ListaDeCartas[i].Pib);
printf("Quantidade de pontos turisticos:%d\n", ListaDeCartas[i].numOfPointTouristic);
float densidadePopulacional = ListaDeCartas[i].population / ListaDeCartas[i].Area;
 float pibPerCapita = ListaDeCartas[i].Pib / ListaDeCartas[i].population;
   printf("Densidade Populacional: %.2f \n", densidadePopulacional);
    printf("PIB per Capita:R$ %.2f \n", pibPerCapita);
    if (i == 0) printf("\n");
}
}

void definirReinicio(){
char resposta[5];
    while (1) {
printf("Digite se deseja reiniciar o jogo sim ou nao ?\n");
    if (fgets(resposta, sizeof(resposta), stdin)) {
            resposta[strcspn(resposta, "\n")] = '\0';//retira a quebra de linha(enter)
        }
        if (strcmp(resposta, "sim") == 0 || strcmp(resposta, "SIM") == 0 ) {
iniciar();            
            break;//interrompe o loop while
        }  
        else if (strcmp(resposta, "nao") == 0 || strcmp(resposta, "NAO") == 0) {
            printf("Fim de jogo.\n");
            break;
        } else {
            printf("Resposta invalida.\n");
        }
    }
}

void iniciar(){
struct Carta ListaDeCartas[2];
capturarDados(ListaDeCartas);
exibirDados(ListaDeCartas);
definirCartaVencedora(ListaDeCartas);
definirReinicio();
}

int main() {
    iniciar();
    return 0;
}
