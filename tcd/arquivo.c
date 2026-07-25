#include <stdio.h>
#include <stdlib.h>
#include "arquivo.h"

int carregar_arquivo(const char *nome, int **vetor){
    int numero, i = 0;
    int *temp;
    int tamvetor = 1000;
    FILE *arquivo = fopen(nome , "r");
    if (arquivo == NULL)
    {
        printf("Erro\n");
        return -1;
    }
    
    while (fscanf(arquivo, "%d", &numero) == 1)
    {   
        if (i >= tamvetor)
        {
            temp = (int *) realloc(*vetor , tamvetor * 10 * sizeof(int));
            if (temp == NULL)
            {
                printf("Erro ao alocar\n");
                fclose(arquivo);
                return -1;
            }
            else{
                *vetor = temp;
            }
            tamvetor *= 10;
        }
        
        (*vetor)[i] = numero;
        i++;
    }
    
    fclose(arquivo);
    return i;
}