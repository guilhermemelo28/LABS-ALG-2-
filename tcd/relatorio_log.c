#ifndef LOGGER_H
#define LOGGER_H

#include "relatorio_log.h"
#include <stdio.h>
#include <time.h>

// Função que grava o log de forma ordenada em um arquivo de texto
void registrar_log(const char *nivel, const char *modulo, const char *mensagem){  // const serve para o vetor de entrada não ser modificado
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
    fprintf(arquivo, "%s [%s] [%s] %s\n", timestamp, nivel, modulo, mensagem);

    // Fecha o arquivo imediatamente para garantir a gravação física no disco
    fclose(arquivo);
}

#endif  
