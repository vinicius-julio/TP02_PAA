/*
 * File:   main.c
 * Authors: Matheus Freitas Martins (3031) / Vinicius Barbosa (3495) / Lucas Barros (3511)
 *
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
    char arquivo[25];
    strcpy(arquivo, ""); //inicializando arquivo como vazio
    FILE *arq = NULL;
    int nLinhaArq, nColunaArq, pontosVida, i, j, valor;
    int **matriz_caverna;
    char valorAux[5];

    printf("CAVERNA\n");
    printf("Insira o arquivo contendo as configuracoes da caverna: \n");
    scanf("%s", arquivo);
    arq = fopen(arquivo, "r");

    while (!arq){
        printf("Erro ao ler o arquivo! \n");
        printf("Insira o arquivo contendo as configuracoes da caverna: \n");
        scanf("%s", arquivo);
        arq = fopen(arquivo, "r");
    }
    printf("ok\n");
    fscanf(arq,"%d %d %d\n", &nLinhaArq, &nColunaArq, &pontosVida);
    matriz_caverna = (int**) malloc(nLinhaArq*sizeof(int*));

    for(i = 0; i < nLinhaArq; i++){
        matriz_caverna[i] = (int*) malloc(nColunaArq*sizeof(int));
    }
    
    i = 0;
    j = 0;
    //le o arquivo
    for(i=0;i<nLinhaArq;i++) {
        for (j = 0; j < nColunaArq; j++) {
            fscanf(arq, "%s ", &valorAux);
            if (strcmp(valorAux,"I")==0){ // se for a letra I, transformamos em um numero
                valor = 1; //por exemplo, 1 representaria I
            }else if(strcmp(valorAux,"F")==0) { //se for letra F transformamos em numero
                valor = 2;
            }else{
                valor = atoi(valorAux);//converte string em int
            }
            matriz_caverna[i][j] = valor;
            printf("%d ", matriz_caverna[i][j]);//testar se a impressão esta correta
        }
        printf("\n");
        }
    return 0;
}
