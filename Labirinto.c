/*
 * File:   Labirinto.c
 * Authors: Matheus Freitas Martins (3031) / Vinicius Barbosa (3495) / Lucas Barros (3511)
 *
*/


#include "Labirinto.h"

void inicializarLabirinto(Labirinto **labirinto, int num_linhas, 
            int num_colunas, int ***matriz_labirinto, int vida, 
            int i_inicio, int j_inicio, int i_fim, int j_fim){
    int i, j;
    (*labirinto) = (Labirinto*) malloc(sizeof(Labirinto));
    (*labirinto)->num_linhas = num_linhas;
    (*labirinto)->num_colunas = num_colunas;        
    (*labirinto)->m = *matriz_labirinto;
    inicializarEstudante(&((*labirinto)->estudante), i_inicio, j_inicio, vida);
    (*labirinto)->pd = (int**) malloc(num_linhas*sizeof(int*));
    for(i = 0; i < num_linhas; i++){
        (*labirinto)->pd[i] = (int*) malloc(num_colunas*sizeof(int));
        for(j = 0; j < num_colunas; j++){
            (*labirinto)->pd[i][j] = (*labirinto)->m[i][j];
        }
    }
    (*labirinto)->i_fim = i_fim;
    (*labirinto)->j_fim = j_fim;
}

void imprimirLabirinto(Labirinto *labirinto){    
    printf("\n**Impressao do Labirinto**\n");
    printf("Numero de linhas: %d\n", labirinto->num_linhas);
    printf("Numero de Colunas: %d\n", labirinto->num_colunas); 
    printf("Inicio: (%d, %d)\n", labirinto->estudante->linha, labirinto->estudante->coluna);
    printf("Fim: (%d, %d)\n", labirinto->i_fim, labirinto->j_fim);            
    imprimirMatrizConfiguracaoLabirinto(labirinto);
    imprimirEstudante(labirinto->estudante);
}

void imprimirMatrizConfiguracaoLabirinto(Labirinto *labirinto){
    int i, j;
    printf("\nConfiguracao do labirinto:\n");
    for(i = 0; i < labirinto->num_linhas; i++){
        for(j = 0; j < labirinto->num_colunas; j++){
            if(i == labirinto->estudante->linha && j == labirinto->estudante->coluna){
		printf("I ");
            } else if(i == labirinto->i_fim && j == labirinto->j_fim){
		printf("F ");
            } else{
		printf("%d ", labirinto->m[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n");
}

void imprimirMatrizPD(Labirinto *labirinto){
    int i, j;
    printf("\nConfiguracao da matriz de Programacao Dinamica:\n");
    for(i = 0; i < labirinto->num_linhas; i++){
        for(j = 0; j < labirinto->num_colunas; j++){
            printf("%d ", labirinto->pd[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int max(int a, int b){
	if(a >= b) 
		return a;
	return b;
}

void maxPD(Labirinto *labirinto){
    int i, j, a, b;
    for(i = labirinto->i_fim; i <= labirinto->estudante->linha; i++){
    	for(j = labirinto->j_fim; j <= labirinto->estudante->coluna; j++){        
    		if(i == labirinto->i_fim && j == labirinto->j_fim){
			// nada aqui (posicao do F)
			a = 0;
			b = 0;
    		} else{
    			if(i == labirinto->i_fim){
    				a = labirinto->pd[i][j-1];
				b = a;
    			} else if(j == labirinto->j_fim){
    				a = labirinto->pd[i-1][j];
    				b = a;
    			} else{
    				a = labirinto->pd[i-1][j];
    				b = labirinto->pd[i][j-1];
    			}
    		}
    		//printf("%d %d %d %d\n", a, b, i, j);
    		labirinto->pd[i][j] = labirinto->pd[i][j] + max(a, b);
    	}
    }
    
    //imprimirMatrizPD(labirinto);
}

void movimentaEstudante(Labirinto *labirinto){
    FILE *f = NULL;
    f = fopen("resultado.txt", "w+");
    if(f == NULL){
        printf("Erro: Arquivo resultado.txt nao pode ser aberto para escrita\n");
        return;
    }
    int i, j;
    i = labirinto->estudante->linha;
    j = labirinto->estudante->coluna;
    if(labirinto->pd[i][j] <= 0){ // pontos de vida zerados eh impossivel sair do labirinto
        fprintf(f, "impossível");
        fclose(f);
        return;
    }   
    fprintf(f, "%d %d\n", i, j);
    while(i != labirinto->i_fim || j != labirinto->j_fim){        
        if(i == labirinto->i_fim){ // mover apenas em j
            j = j-1;
        } else if(j == labirinto->j_fim){ // mover apenas em i
            i = i-1;
        } else{
            if(labirinto->pd[i-1][j] > labirinto->pd[i][j-1]){
                i = i-1;
            } else{
                j = j-1;
            }
        }        
        fprintf(f, "%d %d\n", i, j);
    }
    fclose(f);
}

void freeLabirinto(Labirinto **labirinto){
    int i, j, *r, **r4;
    Labirinto *r2 = *labirinto;
    Estudante *r3 = r2->estudante;
    free(r3);
    for(i = 0; i < r2->num_linhas; i++){        
        r = r2->m[i];
        free(r);
        r = r2->pd[i];
        free(r);        
    }
    r4 = r2->m;
    free(r4);
    r4 = r2->pd;
    free(r4);
    free(r2);
}
