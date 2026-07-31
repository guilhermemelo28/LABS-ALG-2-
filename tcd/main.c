#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "algoritimos.h"
#include "arquivo.h"
#include "relatorio_log.h"

int main()
{
    registrar_log("INICIO", "INICIALIZACAO", "CODIGO INICIALIZADO");
    int opcao, opbusca, opOrdena, opSalvar; // Opcao = Menu, OpBusca para escolher entre Busca Linear e Binaria, OpOrdena para escolher um dos algoritimos de ordenacao
    int buscarelemento;
    int *vet;
    int achou = 0;
    char nomearquivo[100];
    char nomearquivovetor[100];
    int resultado;
    int tamvetor = 1000;

    vet = (int *)malloc(tamvetor * sizeof(int));

    if (vet == NULL)
    {
        registrar_log("MEMORIA", "ALOCACAO", "MEMORIA NAO ALOCADA");
        return 1;
    }
    else
    {
        registrar_log("MEMORIA", "ALOCACAO", "MEMORIA ALOCADA");
        do
        {
            registrar_log("MENU", "OPCAO", "ESCOLHA DA OPCAO");
            printf("===MENU===\n");
            printf("1- Carregar Arquivo de texto.\n");
            printf("2-Busca Elemento (Linear ou Binario)\n");
            printf("3- Ordenar dados: Insert, Bubble, Selection, Merge, Quick, Extra\n");
            printf("4- Gerar relatorio(Log)\n");
            printf("5- Sair\n");
            printf("Digite a opcao\n");
            scanf("%d", &opcao);

            switch (opcao)
            {
            case 1:
                registrar_log("MENU", "OPCAO", "CARREGAR ARQUIVO");
                printf("Digite o nome do arquivo no qual voce quer carregar:\n");
                scanf("%99s", nomearquivo);

                resultado = carregar_arquivo(nomearquivo, &vet);
                if (resultado == -1)
                {
                    registrar_log("ARQUIVO", "FALHA", "ARQUIVO NAO ENCONTRADO");
                    printf("Arquivo nao encontrado! Falha ao carregar o arquivo!\n");
                }
                else
                {
                    registrar_log("ARQUIVO", "SUCESSO", "ARQUIVO ENCONTRADO");
                    printf("Sucesso ao carregar arquivos\n");
                    tamvetor = resultado;
                }

                break;

            case 2:
                registrar_log("MENU", "OPCAO", "SELECIONAR BUSCA");
                printf("Selecione o algoritimo de busca\n");
                    printf("1- Busca Linear\n");
                printf("2- Busca Binaria\n");
                printf("3- Sair\n");
                printf("Digite a opcao:\n");
                scanf("%d", &opbusca);

                printf("Digite o elemento que voce deseja buscar:\n");
                scanf("%d", &buscarelemento);

                switch (opbusca)
                {
                case 1:
                    registrar_log("BUSCA", "TIPO", " SELECIONADO BUSCA LINEAR");
                    achou = buscaLinear(vet, tamvetor, buscarelemento);

                    if (achou != -1)
                    {
                        printf("Elemento encontrado e esta na posicao %d\n", achou + 1);
                        registrar_log("BUSCA", "LINEAR", " ELEMENTO FOI ENCONTRADO PELA BUSCA LINEAR");
                    }
                    else
                    {
                        printf("Elemento nao encontrado\n");
                        registrar_log("BUSCA", "LINEAR", " ELEMENTO  NAO FOI ENCONTRADO PELA BUSCA LINEAR");
                    }
                    break;

                case 2:
                    registrar_log("BUSCA", "TIPO", " SELECIONADO BINARIA");

                    if ((verificaOrdem(vet, tamvetor)) == 1)
                    {
                        registrar_log("BUSCA", "BINARIA", " VETOR ORDENADO");
                        printf(" O vetor esta Ordenado!\n");

                        achou = buscaBinaria(vet, tamvetor, buscarelemento);
                        if (achou != -1)
                        {
                            printf("Elemento encontrado e esta na posicao %d\n", achou);
                            registrar_log("BUSCA", "BINARIA", " ELEMENTO FOI ENCONTRADO PELA BUSCA BINARIA");
                        }
                        else
                        {
                            printf("Elemento nao encontrado\n");
                            registrar_log("BUSCA", "BINARIA", " ELEMENTO FOI ENCONTRADO PELA BUSCA BINARIA");
                        }
                    }
                    else
                    {
                        printf("Vetor esta desordenado, ordene o vetor!\n");
                        registrar_log("BUSCA", "BINARIA", "VETOR DESORDENADO");
                        break;
                    }
                }
                break;

            case 3:
                registrar_log("MENU", "OPCAO", "SELECIONAR ALGORITIMO DE ORDENACAO");
                printf("Selecione o algoritimo de Ordenacao\n");
                printf("1- Insert Sort\n");
                printf("2-Bubble Sort\n");
                printf("3-Selection Sort\n");
                printf("4-Merge Sort\n");
                printf("5- Quick Sort\n");
                printf("6- Extra\n");
                printf("7-Sair\n");

                printf("Selecione a opcao:\n");
                scanf("%d", &opOrdena);

                switch (opOrdena)
                {

                case 1:
                    registrar_log("ORDENACAO", "OPCAO", "SELECIONADO INSERTION SORT");
                    printf("Selecionado: Insertion Sort\n");
                    insertionsort(vet, tamvetor);
                    printf("Vetor ordenado:\n");

                    for (int i = 0; i < tamvetor; i++)
                    {
                        printf("%d\n", vet[i]);
                    }
                    break;

                case 2:
                    registrar_log("ORDENACAO", "OPCAO", "SELECIONADO BUBBLE SORT");
                    printf("Selecionado: Bubble Sort\n");
                    Bubblesort(vet, tamvetor);
                    printf("Vetor ordenado:\n");

                    for (int i = 0; i < tamvetor; i++)
                    {
                        printf("%d\n", vet[i]);
                    }
                    break;

                case 3:
                    registrar_log("ORDENACAO", "OPCAO", "SELECIONADO SELECTION SORT");
                    printf("Selecionado: Selection Sort\n");
                    selectionsort(vet, tamvetor);
                    printf("Vetor ordenado:\n");

                    for (int i = 0; i < tamvetor; i++)
                    {
                        printf("%d\n", vet[i]);
                    }
                    break;

                case 4:
                    registrar_log("ORDENACAO", "OPCAO", "SELECIONADO MERGE SORT");
                    printf("Selecionado: Merge Sort\n");
                    mergesort(vet, 0, tamvetor - 1);
                    printf("Vetor ordenado:\n");

                    for (int i = 0; i < tamvetor; i++)
                    {
                        printf("%d\n", vet[i]);
                    }
                    break;

                case 5:
                    registrar_log("ORDENACAO", "OPCAO", "SELECIONADO QUICK SORT");
                    printf("Selecionado: Quick Sort\n");

                    quicksort(vet, 0, tamvetor - 1);
                    printf("Vetor ordenado:\n");

                    for (int i = 0; i < tamvetor; i++)
                    {
                        printf("%d\n", vet[i]);
                    }
                    break;

                case 6:
                    registrar_log("ORDENACAO", "OPCAO", "SELECIONADO EXTRA: INTRO SORT");
                    printf("Selecionado Extra: IntroSort\n");
                    break;

                }
                
                
                if( verificaOrdem(vet, tamvetor) == 1)
                {
                    registrar_log("ORDENACAO", "SUCESSO", "VETOR ORDENADO");
                    printf("Vetor foi ordenado com sucesso!\n");

                }

                if (opOrdena >= 1 && opOrdena <= 6)
                {
                    registrar_log("ARQUIVO ORDENACAO", "OPCAO", "SALVAR ARQUIVO");
                    printf("Deseja salvar o vetor ordenado em um arquivo separado?\n");
                    printf("1- Sim\n");
                    printf("2- Nao\n");
                    scanf("%d", &opSalvar);

                    if (opSalvar == 1)
                    {
                        printf("Digite o nome do arquivo para salvar:\n");
                        scanf("%99s", nomearquivovetor);

                        resultado = salvar_vetor(nomearquivovetor, vet, tamvetor);

                        if (resultado == -1)
                        {
                            printf("Erro ao salvar arquivo!\n");
                        }
                        else
                        {
                            registrar_log("ARQUIVO ORDENACAO", "OPCAO", "ARQUIVO SALVO");
                            printf("Arquivo salvo com sucesso!\n");
                        }
                    }
                    else
                    {
                        registrar_log("ARQUIVO ORDENACAO", "OPCAO", "ARQUIVO NAO SALVO");
                        printf("Arquivo nao foi salvado!\n");
                    }
                }
                break;
                case 4:
                printf("Arqivo de log gerado!\n");
                registrar_log("MENU", "OPCAO", "ARQUIVO DE LOG GERADO");
                break;

                default:
                registrar_log("MENU", "OPCAO", "SAIR DO PROGRAMA");
                printf("Saindo...");
                break;
            }

        } while (opcao != 5);
        registrar_log("FINALIZACAO", "FINAL", "ARQUIVO ENCERRADO");
        free(vet);
    }
}
