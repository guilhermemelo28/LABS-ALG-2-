    #include<stdio.h>
    #include<stdlib.h>
    #include"algoritimos.h"
    #include "arquivo.h"

    int main()
    {
        int opcao,opbusca,opOrdena;//Opcao = Menu, OpBusca para escolher entre Busca Linear e Binaria, OpOrdena para escolher um dos algoritimos de ordenacao
        int buscarelemento;
        int *vet;
        int achou = 0,carregou = 0;
        char nomearquivo[100];
        int resultado;
        int tamvetor = 1000;

        vet = (int *) malloc(tamvetor * sizeof(int));
    
        if(vet == NULL)
        {
            return 1;
        }

        do
        {
            printf("===MENU===\n");
            printf("1- Carregar Arquivo de texto.\n");
            printf("2-Busca Elemento (Linear ou Binario)\n");
            printf("3- Ordenar dados: Insert, Bubble, Selection, Merge, Quick, Extra\n");
            printf("4- Gerar relatório(Log)\n");
            printf("5- Sair\n");
            printf("Digite a opcao\n");
            scanf("%d",&opcao);
            
            switch(opcao)
            {
                case 1:
                printf("Digite o nome do arquivo no qual você quer carregar:\n");
                scanf("%99s" , nomearquivo);

                resultado = carregar_arquivo(nomearquivo, &vet);
                if (resultado == -1)
                {
                    printf("Arquivo não encontrado! Falha ao carregar o arquivo!\n");
                }
                else{
                    printf("Sucesso ao carregar arquivos\n");
                    tamvetor = resultado;
                    carregou = 1;
                }
                
                break;
                
                case 2:
                printf("Selecione o algoritimo de busca\n");
                printf("1- Busca Linear\n");
                printf("2- Busca Binaria\n");
                printf("3- Sair\n");
                printf("Digite a opcao:\n");
                scanf("%d",&opbusca);

                printf("Digite o elemento que voce deseja buscar:\n");
                scanf("%d",&buscarelemento);
                    if(carregou == 1)
                    {
                        switch(opbusca)
                        {
                            case 1:
                                printf("Selecionado Busca Linear\n");
                                achou = buscaLinear(vet,tamvetor,buscarelemento);

                                if(achou != -1)
                                {
                                    printf("Elemento encontrado e esta na posicao %d\n",achou + 1);
                                }
                                else{
                                    printf("Elemento nao encontrado\n");
                                }
                                break;

                            case 2:
                                printf("Selecionado Busca Binaria\n");

                                if((verificaOrdem(vet,tamvetor)) == 1)
                                {
                                    printf(" O vetor esta Ordenado!\n");

                                    achou = buscaBinaria(vet,tamvetor,buscarelemento);
                                    if(achou != -1)
                                    {
                                        printf("Elemento encontrado e esta na posicao %d\n",achou);
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
                        }
                        else
                        {
                            printf("Erro! Nao foi possivel fazer a busca, pois nenhum arquivo foi carregado!\n");
                        }
                    break;

                case 3:
                printf("Selecione o algoritimo de Ordenacao\n");
                printf("1- Insert Sort\n");
                printf("2-Bubble Sort\n");
                printf("3-Selection Sort\n");
                printf("4-Merge Sort\n");
                printf("5- Quick Sort\n");
                printf("6- Extra\n");
                printf("7-Sair\n");

                printf("Selecione a opcao:\n");
                scanf("%d",&opOrdena);
                if(carregou == 1)
                {
                    switch (opOrdena)
                    {
                        case 1:

                        break;
                        case 2:
                            printf("Selecionado: Bubble Sort\n");
                            Bubblesort(vet,tamvetor);
                            printf("Vetor ordenado:\n");

                            for(int i = 0; i < tamvetor ; i++)
                            {
                                printf("%d\n",vet[i]);
                            }
                            break;

                        case 3:
                            printf("Selecionado: Selection Sort\n");
                            selectionsort(vet,tamvetor);
                            printf("Vetor ordenado:\n");

                            for(int i = 0; i < tamvetor ; i++)
                            {
                                printf("%d\n",vet[i]);
                            }
                            break;

                        case 4:
                            printf("Selecionado: Merge Sort\n");
                            mergesort(vet,0,tamvetor - 1);
                            printf("Vetor ordenado:\n");

                            for(int i = 0; i < tamvetor ; i++)
                            {
                                printf("%d\n",vet[i]);
                            }
                            break;

                        case 5:
                            printf("Selecionado: Quick Sort\n");

                            quicksort(vet,0,tamvetor - 1);
                            printf("Vetor ordenado:\n");

                            for(int i = 0; i < tamvetor ; i++)
                            {
                                printf("%d\n",vet[i]);
                            }
                            break;

                            case 6:
                                printf("Selecionado Extra: IntroSort\n");


                    }
                }
                else
                {
                    printf("Erro! Nao foi possivel fazer a ordenação, pois nenhum arquivo foi carregado!\n");
                }
            }
            
            
        }while(opcao != 5);
        free(vet);
    }
    