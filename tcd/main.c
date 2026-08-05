#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "algoritimos.h"
#include "arquivo.h"
#include "relatorio_log.h"
#include <windows.h>


int main()
{
    LARGE_INTEGER frequency;
    LARGE_INTEGER inicio, fim;
    double elapsedtime;
    double somaTempo = 0.0;
    int opcao, opbusca, opOrdena, opSalvar; // Opcao = Menu, OpBusca para escolher entre Busca Linear e Binaria, OpOrdena para escolher um dos algoritimos de ordenacao
    int buscarelemento;
    int *vet;
    int algExecutado = 0;
    int achou = 0;
    int arquivo_carregado = 0;
    char nomearquivo[100];
    char nomearquivovetor[100];
    int resultado;
    int tamvetor = 1000;
    int i;
    int *vettemp = NULL;
    Log relatorioLog = {0};     

    vet = (int *)malloc(tamvetor * sizeof(int));

    if (vet == NULL)
    {
        return 1;
    }
    else
    {
        do
        {
            ;
            printf("===MENU===\n");
            printf("1- Carregar Arquivo de texto.\n");
            printf("2- Busca Elemento (Linear ou Binario)\n");
            printf("3- Ordenar dados: Insert, Bubble, Selection, Merge, Quick, Extra(Intro Sort)\n");
            printf("4- Gerar relatorio(Log)\n");
            printf("5- Sair\n");
            printf("Digite a opcao\n");
            scanf("%d", &opcao);

            switch (opcao)
            {
            case 1:
                printf("Digite o nome do arquivo no qual voce quer carregar:\n");
                scanf("%99s", nomearquivo);

                resultado = carregar_arquivo(nomearquivo, &vet);
                if (resultado == -1)
                {
                    printf("Arquivo nao encontrado! Falha ao carregar o arquivo!\n");
                    arquivo_carregado = 0;
                }
                else
                {
                    printf("Sucesso ao carregar arquivos\n");
                    tamvetor = resultado;                    
                    arquivo_carregado = 1;
                }

                break;
                case 2:

                    if(arquivo_carregado == 0)
                    {
                        printf("Necessario carregar um arquivo\n");
                        break;
                    }

                    printf("Digite o elemento que voce deseja buscar:\n");
                    scanf("%d", &buscarelemento);
                    printf("Selecione o algoritimo de busca\n");
                    printf("1- Busca Linear\n");
                    printf("2- Busca Binaria\n");
                    printf("3- Sair\n");
                    printf("Digite a opcao:\n");
                    scanf("%d", &opbusca);


                    switch (opbusca)
                    {
                        algExecutado = 1;
                    case 1:
                        QueryPerformanceFrequency(&frequency);

                        for(int i = 0; i < 100; i++){
    
                        QueryPerformanceCounter(&inicio);
                        
                        achou = buscaLinear(vet, tamvetor, buscarelemento);
                        algExecutado = 1;

                        QueryPerformanceCounter(&fim);
                        elapsedtime = (fim.QuadPart - inicio.QuadPart) * 1000.0 / frequency.QuadPart;
                        somaTempo += elapsedtime;
                        }
                        
                        snprintf(relatorioLog.log1, sizeof(relatorioLog.log1),
                        "[BUSCA][BUSCALINEAR][MEDIADETEMPO:%.16lfms]", (somaTempo / 100));
                        if (achou != -1)
                        {
                            printf("Elemento encontrado e esta na posicao %d\n", achou + 1);
                        }
                        else
                        {
                            printf("Elemento nao encontrado\n");
                        }
                        break;

                    case 2:
                        if ((verificaOrdem(vet, tamvetor)) == 1)
                        {
                            somaTempo = 0.0;
                            printf(" O vetor esta Ordenado!\n");

                            QueryPerformanceFrequency(&frequency);
                            for(i = 0; i < 100; i++){
                            QueryPerformanceCounter(&inicio);

                            achou = buscaBinaria(vet, tamvetor, buscarelemento);
                            algExecutado = 1;

                            QueryPerformanceCounter(&fim);
                            elapsedtime = (fim.QuadPart - inicio.QuadPart) * 1000.0 / frequency.QuadPart;
                            somaTempo += elapsedtime;
                            }

                            snprintf(relatorioLog.log2, sizeof(relatorioLog.log2),
                            "[BUSCA][BUSCABINARIA][MEDIADETEMPO:%.16lfms]", somaTempo / 100);
                            
                            if (achou != -1)
                            {
                                printf("Elemento encontrado e esta na posicao %d\n", achou);
                            }
                            else
                            {
                                printf("Elemento nao encontrado\n");
                            }
                        }
                        else
                        {
                            printf("Vetor esta desordenado, ordene o vetor!\n");
                            break;
                        }

                    }
                    break;
                case 3:

                    if(arquivo_carregado == 0)
                    {
                        printf("Necessario carregar um arquivo\n");
                        break;
                    }
                    printf("Selecione o algoritimo de Ordenacao\n");
                    printf("1- Insertion Sort\n");
                    printf("2- Bubble Sort\n");
                    printf("3- Selection Sort\n");
                    printf("4- Merge Sort\n");
                    printf("5- Quick Sort\n");
                    printf("6- Extra(Intro Sort)\n");
                    printf("7- Sair\n");

                    printf("Selecione a opcao:\n");
                    scanf("%d", &opOrdena);

                    
                    switch (opOrdena)
                    {
                    
                    case 1:
                        printf("Selecionado: Insertion Sort\n");
                            somaTempo = 0.0;
                            QueryPerformanceFrequency(&frequency);
                            for(int i = 0; i < 100; i++){
                            
                                copiavetor(vet, &vettemp, tamvetor);
                            
                                QueryPerformanceCounter(&inicio);

                                insertionsort(vettemp, tamvetor);

                                QueryPerformanceCounter(&fim);
                                algExecutado = 1;
                            
                                elapsedtime = (fim.QuadPart - inicio.QuadPart) * 1000.0 / frequency.QuadPart;
                                somaTempo += elapsedtime;
                            }
                        
                            snprintf(relatorioLog.log3, sizeof(relatorioLog.log3),
                            "[ORDENACAO][INSERTIONSORT][MEDIADETEMPO:%.16lfms]", (somaTempo / 100));
                        printf("Vetor ordenado:\n");

                        for (int i = 0; i < tamvetor; i++)
                        {
                            printf("%d\n", vettemp[i]);
                        }
                        break;

                    case 2:
                    printf("Selecionado: Bubble Sort\n");
                    somaTempo = 0.0;
                    QueryPerformanceFrequency(&frequency);
                        for(i = 0; i < 100; i++){
                            
                            copiavetor(vet, &vettemp, tamvetor);
                            
                            QueryPerformanceCounter(&inicio);
                            Bubblesort(vettemp, tamvetor);
                            QueryPerformanceCounter(&fim);

                            algExecutado = 1;
                            
                            elapsedtime = (fim.QuadPart - inicio.QuadPart) * 1000.0 / frequency.QuadPart;
                            somaTempo += elapsedtime;
                            }
                            snprintf(relatorioLog.log4, sizeof(relatorioLog.log4),
                            "[ORDENACAO][BUBBLESORT][MEDIADETEMPO:%.16lfms]", (somaTempo/100));
                        printf("Vetor ordenado:\n");
                        printf("Vetor ordenado:\n");

                        for (int i = 0; i < tamvetor; i++)
                        {
                            printf("%d\n", vettemp[i]);
                        }
                        break;

                    case 3:
                        printf("Selecionado: Selection Sort\n");
                            somaTempo = 0.0;
                            QueryPerformanceFrequency(&frequency);
                            for(i = 0; i < 100; i++){
                                copiavetor(vet, &vettemp, tamvetor);
                                QueryPerformanceCounter(&inicio);

                                selectionsort(vettemp, tamvetor);
                                algExecutado = 1;

                                QueryPerformanceCounter(&fim);
                                elapsedtime = (fim.QuadPart - inicio.QuadPart) * 1000.0 / frequency.QuadPart;
                            }      
                            snprintf(relatorioLog.log5, sizeof(relatorioLog.log5),
                            "[ORDENACAO][SELECTIONSORT][MEDIADETEMPO:%.16lfms]", (somaTempo/100));
                        
                        printf("Vetor ordenado:\n");

                        for (int i = 0; i < tamvetor; i++)
                        {
                            printf("%d\n", vet[i]);
                        }
                        break;

                    case 4:
                        somaTempo = 0.0;
                        printf("Selecionado: Merge Sort\n");

                            QueryPerformanceFrequency(&frequency);
                            for(i = 0; i < 100; i++){
                                copiavetor(vet, &vettemp, tamvetor);
                                QueryPerformanceCounter(&inicio);

                                mergesort(vettemp, 0, tamvetor - 1);
                                algExecutado = 1;

                                QueryPerformanceCounter(&fim);
                                elapsedtime = (fim.QuadPart - inicio.QuadPart) * 1000.0 / frequency.QuadPart;
                                somaTempo += elapsedtime;
                            }
                            snprintf(relatorioLog.log6, sizeof(relatorioLog.log6),
                            "[ORDENACAO][MERGESORT][MEDIADETEMPO:%.16lfms]", (somaTempo/100));
                        printf("Vetor ordenado:\n");

                        for (int i = 0; i < tamvetor; i++)
                        {
                            printf("%d\n", vettemp[i]);
                        }
                        break;

                    case 5:
                        printf("Selecionado: Quick Sort\n");
                            somaTempo = 0.0;
                            QueryPerformanceFrequency(&frequency);
                            for(i = 0; i < 100; i++){
                                copiavetor(vet, &vettemp, tamvetor);
                                QueryPerformanceCounter(&inicio);

                                quicksort(vettemp, 0, tamvetor - 1);
                                algExecutado = 1;

                                QueryPerformanceCounter(&fim);
                                elapsedtime = (fim.QuadPart - inicio.QuadPart) * 1000.0 / frequency.QuadPart;
                                somaTempo += elapsedtime;
                            }
                            snprintf(relatorioLog.log7, sizeof(relatorioLog.log7),
                            "[ORDENACAO][QUICKSORT][MEDIADETEMPO:%.16lfms]", (somaTempo/100));
                        
                        printf("Vetor ordenado:\n");

                        for (int i = 0; i < tamvetor; i++)
                        {
                            printf("%d\n", vettemp[i]);
                        }
                        break;

                    case 6:
                        printf("Selecionado Extra: IntroSort\n");
                        
                        QueryPerformanceFrequency(&frequency);
                        for(i = 0; i < 100; i++){
                            
                            copiavetor(vet, &vettemp, tamvetor);
                            
                            QueryPerformanceCounter(&inicio);
                            introsort(vettemp, tamvetor);
                            QueryPerformanceCounter(&fim);

                            algExecutado = 1;
                            
                            elapsedtime = (fim.QuadPart - inicio.QuadPart) * 1000.0 / frequency.QuadPart;
                            somaTempo += elapsedtime;
                            }
                            snprintf(relatorioLog.log8, sizeof(relatorioLog.log8),
                            "[ORDENACAO][INTROSORT][MEDIADETEMPO:%.16lfms]", (somaTempo/100));
                        printf("Vetor ordenado:\n");
                        printf("Vetor ordenado:\n");

                        for (int i = 0; i < tamvetor; i++)
                        {
                            printf("%d\n", vettemp[i]);
                        }
                        break;
                    }

                    if (verificaOrdem(vettemp, tamvetor) == 1)
                    {
                        printf("Vetor foi ordenado com sucesso!\n");
                    }

                    if (opOrdena >= 1 && opOrdena <= 6)
                    {
                        printf("Deseja salvar o vetor ordenado em um arquivo separado?\n");
                        printf("1- Sim\n");
                        printf("2- Nao\n");
                        scanf("%d", &opSalvar);

                        if (opSalvar == 1)
                        {
                            printf("Digite o nome do arquivo para salvar:\n");
                            scanf("%99s", nomearquivovetor);

                            resultado = salvar_vetor(nomearquivovetor, vettemp, tamvetor);

                            if (resultado == -1)
                            {
                                printf("Erro ao salvar arquivo!\n");
                            }
                            else
                            {
                                printf("Arquivo salvo com sucesso!\n");
                            }
                        }
                        else
                        {
                            printf("Arquivo nao foi salvado!\n");
                        }
                    }
                    break;
                case 4:
                    if(algExecutado == 0)
                    {
                        printf("Necessario executar algoritimo\n");
                        break;
                    }else{
                        printf("Arqivo de log gerado!\n");
                        registrar_log(&relatorioLog);
                    }
                    
                    
                    break;

                    
                    default:
                    
                    if(opcao == 5)
                    {
                        free(vet);
                        free(vettemp);
                        printf("Saindo...\n");
                        break;
                    }
                    
                    else
                    {
                        printf("Opcao invalida!\n");
                    }
            }
        }while (opcao != 5);
    }
    return 0;
}