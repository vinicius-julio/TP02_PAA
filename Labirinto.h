/*
 * File:   Labirinto.h
 * Authors: Matheus Freitas Martins (3031) / Vinicius Barbosa (3495) / Lucas Barros (3511)
 *
*/

#ifndef LABIRINTO_H
#define LABIRINTO_H

#include "Estudante.h"

#define MODOANALISE 1 // 1 para ativado 0 para desativado
#define INICIO 0
#define FIM 1

#ifdef __cplusplus
extern "C" {
#endif

    typedef struct Labirinto{
        int num_linhas;
        int num_colunas;
        Estudante *estudante; // guarda posicao e quantidade de chaves restantes
        int **m; // matriz do labirinto
        int **pd; // matriz para a programacao dinamica 
        int i_fim;
        int j_fim;
    } Labirinto;
    
    void inicializarLabirinto(Labirinto **labirinto, int num_linhas, 
            int num_colunas, int ***matriz_labirinto, int vida,
            int i_inicio, int j_inicio, int i_fim, int j_fim);
    void imprimirLabirinto(Labirinto *labirinto);
    void imprimirMatrizConfiguracaoLabirinto(Labirinto *labirinto);
    void imprimirMatrizPD(Labirinto *labirinto);
    void maxPD(Labirinto *labirinto);
    void freeLabirinto(Labirinto **labirinto);
    void movimentaEstudante(Labirinto *labirinto);
    


#ifdef __cplusplus
}
#endif

#endif /* LABIRINTO_H */

