#ifndef LOGGER_H
#define LOGGER_H
#include "relatorio_log.h"
#include <stdio.h>
#include <time.h>


void time_executing_log(const char *nivel, const char *modulo, const double timeexe){
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

    // Grava as informações de forma ordenada
    fprintf(arquivo, "%s [%s] [%s] [TEMPO DE EXECUCAO %.16lf ms]\n", timestamp, nivel, modulo, timeexe);

    // Fecha o arquivo imediatamente para garantir a gravação física no disco
    fclose(arquivo);
}

#endif  
