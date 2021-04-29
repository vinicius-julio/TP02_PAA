#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void GeraCaverna(int nLinha, int nColuna, int hpPlayer){
    int l_Estudante, c_Estudante;
    int l_Saida, c_Saida;
    char *posicao;
    char *objeto[8] = {"0","-10","-20","0","-10","+20", "0", "0"};//objetos a serem colocados na caverna
    srand( (unsigned)time(NULL) );
    char arquivo[25];
    FILE *arq;
    l_Estudante = rand() % nLinha; // estudante fica em uma posição aleatoria da linha
    c_Estudante = rand() % nColuna; // estudante fica em uma posição aleatoria da coluna
    l_Saida = rand() % nLinha; // saida fica em uma posição aleatoria da linha
    c_Saida = rand() % nColuna; // saida fica em uma posição aleatoria da coluna
    printf("Digite o nome do novo arquivo (arquivo.txt): \n");
    scanf("%s", arquivo);
    arq = fopen(arquivo, "w");
    if(arq == NULL){
        printf ("Erro ao criar o arquivo.\n");
    }
    else{
        fprintf(arq, "%d %d %d \n", nLinha, nColuna, hpPlayer);
        for(int i = 0; i < nLinha; i++){
            for(int j = 0; j < nColuna; j++){
                if( i == l_Estudante && j == c_Estudante){ // escreve I na posição onde o estudante está.
                    posicao = "I";
                }
                else if(i == l_Saida && j == c_Saida){
                    posicao = "F";
                }
                else{
                    posicao = objeto[rand() % 8];
                }
                fprintf(arq, "%s ", posicao);
            }
            fputc('\n', arq); //quebra de linha
        }
        fclose(arq);
    }

}


int main (){
    int nLinha, nColuna, hp;

    printf("Digite o Numero de linhas: \n");
    scanf("%d", &nLinha);

    printf("Digite o Numero de colunas: \n");
    scanf("%d", &nColuna);

    printf("Digite o Numero de Vida: \n");
    scanf("%d", &hp);

    GeraCaverna(nLinha, nColuna, hp);
}
