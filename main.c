/*
 * File:   main.c
 * Authors: Matheus Freitas Martins (3031) / Vinicius Barbosa (3495) / Lucas Barros (3511)
 *
*/

#include <stdio.h>
#include <stdlib.h>

#include "Labirinto.h"

void teste(){
    int i, j, num_linhas = 4, num_colunas = 5, vida = 40;
    int i_inicio = 3, j_inicio = 4, i_fim = 1, j_fim = 0;
    int **matriz_labirinto;
    int aux[][5] = {        
        {-20, 0, -20, 0, 0},
        {0, -10, -10, -10, -10},
        {-20, 0, 0, 0, 20},
        {0, 0, -10, 0, 0}
    };
    matriz_labirinto = (int**) malloc(num_linhas*sizeof(int*));
    for(i = 0; i < num_linhas; i++){
        matriz_labirinto[i] = (int*) malloc(num_colunas*sizeof(int*));
        for(j = 0; j < num_colunas; j++){
            matriz_labirinto[i][j] = aux[i][j];
        }
    }    
    Labirinto *labirinto;
    inicializarLabirinto(&labirinto, num_linhas, num_colunas, &matriz_labirinto, vida,
            i_inicio, j_inicio, i_fim, j_fim);
    imprimirLabirinto(labirinto);
    imprimirMatrizPD(labirinto);
    maxPD(labirinto);
    imprimirMatrizPD(labirinto);
    movimentaEstudante(labirinto);
    freeLabirinto(&labirinto);
}

/*
 * 
 */
int main(int argc, char** argv) {
    //teste();
    if(argc < 2){
        printf("Passe o nome do arquivo ao executar.\n");
        return 0;
    }    
    FILE *f = NULL;
    f = fopen(argv[1], "r");
    if(f == NULL){
        printf("Nao foi possivel abrir o arquivo %s.\n", argv[1]);
        return 0;
    }
    int i, j, num_linhas, num_colunas, vida;
    int i_inicio, j_inicio, i_fim, j_fim;
    char caractere;
    int **matriz_labirinto;
    fscanf(f, "%d", &num_linhas);
    fscanf(f, "%d", &num_colunas);
    fscanf(f, "%d", &vida);
    
    matriz_labirinto = (int**) malloc(num_linhas*sizeof(int*));
    for(i = 0; i < num_linhas; i++){
        matriz_labirinto[i] = (int*) malloc(num_colunas*sizeof(int*));
        for(j = 0; j < num_colunas; j++){
            caractere = fgetc(f);            
            if(caractere == 'I'){
                i_inicio = i;
                j_inicio = j;
                matriz_labirinto[i][j] = 0;
            } else if(caractere == 'F'){                
                i_fim = i;
                j_fim = j;
                matriz_labirinto[i][j] = 0;
            } else{
                fseek(f, -1, SEEK_CUR); // voltando uma posicao de leitura por causa do caractere lido
                fscanf(f, "%d", &matriz_labirinto[i][j]);
                fgetc(f);
            }
        }
    } 
    fclose(f);
    Labirinto *labirinto;
    inicializarLabirinto(&labirinto, num_linhas, num_colunas, &matriz_labirinto, vida,
            i_inicio, j_inicio, i_fim, j_fim);
    imprimirLabirinto(labirinto);
    imprimirMatrizPD(labirinto);
    maxPD(labirinto);
    imprimirMatrizPD(labirinto);
    movimentaEstudante(labirinto);
    freeLabirinto(&labirinto);
    return 0;
}

