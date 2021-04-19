/*
 * File:   Estudante.c
 * Authors: Matheus Freitas Martins (3031) / Vinicius Barbosa (3495) / Lucas Barros (3511)
 *
*/


#include "Estudante.h"

void inicializarEstudante(Estudante **estudante, int linha, int coluna, int vida){
    (*estudante) = (Estudante*) malloc(sizeof(Estudante));
    (*estudante)->linha = linha;
    (*estudante)->coluna = coluna;    
    (*estudante)->vida = vida;    
}

void imprimirEstudante(Estudante *estudante){
    printf("\n**Impressao do Estudante**\n");
    printf("Linha: %d\nColuna: %d\n", estudante->linha, estudante->coluna);
    printf("Vida: %d\n", estudante->vida);
}
