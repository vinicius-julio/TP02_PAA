/*
 * File:   Estudante.h
 * Authors: Matheus Freitas Martins (3031) / Vinicius Barbosa (3495) / Lucas Barros (3511)
 *
*/

#ifndef ESTUDANTE_H
#define ESTUDANTE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAO_CHEGOU_AO_OBJETIVO 0
#define CHEGOU_AO_OBJETIVO 1

#ifdef __cplusplus
extern "C" {
#endif

    typedef struct Estudante{ // guarda posicao e quantidade de chaves restantes
        int linha;
        int coluna;
        int vida;
    } Estudante;
    
    void inicializarEstudante(Estudante **estudante, int linha, int coluna, int vida);
    void imprimirEstudante(Estudante *estudante);


#ifdef __cplusplus
}
#endif

#endif /* ESTUDANTE_H */

