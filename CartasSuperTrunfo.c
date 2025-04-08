#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    char nome[50];
    unsigned long int popu, pt;
    float area, pib, pibpc, dp;
}Paises;
Paises lista_paises[206];
void cadastrar_carta(); //pag 41
void consultar_cartas(); //pag 58
void comparar(); //pag 66
int n=0;
int main(){
    int ope;
    do{
        printf("\n-----Menu-----\n");
        printf("1 - Cadastrar Cartas\n");
        printf("2 - Banco de Cartas\n");
        printf("3 - Comparar\n");
        printf("4 - Sair\n");
        scanf("%d",&ope);
        system("cls");
        switch (ope){
            case 1:
                cadastrar_carta();
                break;
            case 2:
                consultar_cartas();
                break;
            case 3:
                comparar();
                break;
            default:
                printf("Invalido");
                break;
        }
    }while (ope != 4);
    return 0;
}
void cadastrar_carta(){
    printf("Informe o nome do pais: ");
    scanf(" %[^\n]", lista_paises[n].nome);
    printf("Informe a populacao do pais: ");
    scanf("%lu",&lista_paises[n].popu);
    printf("Informe a quantiade de pontos turisticos do pais: ");
    scanf("%lu",&lista_paises[n].pt);
    printf("Informe a area do pais: ");
    scanf("%f",&lista_paises[n].area);
    printf("Informe o pib do pais: ");
    scanf("%f",&lista_paises[n].pib);
    lista_paises[n].dp = lista_paises[n].popu/lista_paises[n].area;
    lista_paises[n].pibpc = lista_paises[n].pib/lista_paises[n].popu;
    n++;
    return;
}

void consultar_cartas(){
    printf("Cartas cadastradas: \n");
    for (int i=0;i<n;i++){
        printf("\n");
        printf("Nome: %s\nPopulacao: %lu\nPontos Turisticos: %lu\nArea: %.2f\nPib: %.2f\nDensidade populacional: %.2f\nPib per Capita: %.2f\n",lista_paises[i].nome,lista_paises[i].popu,lista_paises[i].pt,lista_paises[i].area,lista_paises[i].pib,lista_paises[i].dp,lista_paises[i].pibpc);
    }
}

void comparar(){
    float soma1 = 0, soma2 = 0;
    char nome_busca1[50], nome_busca2[50];
    printf("Informe o nome do primeiro pais para comparar: ");
    scanf(" %[^\n]", nome_busca1);
    printf("Informe o nome do segundo pais para comparar: ");
    scanf(" %[^\n]", nome_busca2);
    int idx1 = buscar(nome_busca1);
    int idx2 = buscar(nome_busca2);
    if (idx1==-1||idx2==-1){
        printf("Invalido");
        return;
    }
    soma1 = lista_paises[idx1].popu+lista_paises[idx1].pt+lista_paises[idx1].pib+lista_paises[idx1].pibpc+lista_paises[idx1].area-lista_paises[idx1].dp;
    soma2 = lista_paises[idx2].popu+lista_paises[idx2].pt+lista_paises[idx2].pib+lista_paises[idx2].pibpc+lista_paises[idx2].area-lista_paises[idx2].dp;
    if (soma1 > soma2){
        printf("Vencedor: %s\n%s: %.2f\n%s: %.2f",nome_busca1,nome_busca1,soma1,nome_busca2,soma2);
    }else if (soma2 > soma1){
        printf("Vencedor: %s\n%s: %.2f\n%s: %.2f",nome_busca2,nome_busca2,soma2,nome_busca1,soma1);
    }else{
        printf("Empate");
    }
}

int buscar(char nomedebusca[]){
    for (int i=0;i<n;i++) {
        if (strcmp(lista_paises[i].nome, nomedebusca) == 0) {
            return i;
        }
    }
    return -1;
}