#ifndef LOGGER_H
#define LOGGER_H
#include "relatorio_log.h"
#include <stdio.h>
#include<stdlib.h>
#include <time.h>


void registrar_log(const Log *relatoriolog){
    // Abre o arquivo de texto no modo append (adiciona ao final sem apagar o anterior)
    FILE *arquivo = fopen("log_sistema.txt", "a");
    if (arquivo == NULL){
        printf("Aviso: Não foi possível gravar o log no disco.\n");
        return;
    }
    // Captura a data e hora atual do sistema
    time_t agora;
    time(&agora);
    struct tm *info = localtime(&agora);
    char timestamp[20];
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", info);

    const char *logs[] = {
        relatoriolog->log1, relatoriolog->log2, relatoriolog->log3, relatoriolog->log4,
        relatoriolog->log5, relatoriolog->log6, relatoriolog->log7, relatoriolog->log8
    };

    // Imprime apenas os logs que possuem conteúdo
    for (int i = 0; i < 8; i++) {
        if (logs[i][0] != '\0') {
            fprintf(arquivo, "%s\n", logs[i]);
        }
    }

    // Fecha o arquivo imediatamente para garantir a gravação física no disco
    fclose(arquivo);
}
//Recebe o vetor que vai ser copiado, ponteiro de ponteiro do vetor que queremos armazenar a copia, usamos ponteiro de ponteiro 
// para que a função pode alterar o endereço armazenado no ponteiro vettemp original, e o tamanho
int copiavetor(const int *vet, int **vettemp, int tamanho)
{
    int *novo = (int*) realloc(*vettemp, tamanho * sizeof(int));

    if (novo == NULL)
    {
        return 0;
    }

    *vettemp = novo;

    for (int i = 0; i < tamanho; i++)
    {
        (*vettemp)[i] = vet[i];
    }

    return 1;
}

#endif  
