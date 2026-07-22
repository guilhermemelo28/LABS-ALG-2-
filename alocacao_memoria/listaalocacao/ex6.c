#include<stdio.h>
#include<stdlib.h>

int main()
{
    int tam,opcao,posicao,valor,busca,qtd,achou;
    int *point;

    printf("Digite quantos Bytes(essa quantidade de bytes tem que ser um numero multiplo do tamanho do inteiro) serao alocados:\n");
    scanf("%d",&tam);

    if(tam % sizeof(int) != 0 )
    {
        printf("Voce nao digitou um multiplo de 4");
    }
    else
    {
        qtd = tam / sizeof(int);
    point = (int*) calloc(qtd,sizeof(int));

    if(point == NULL)
    {
        return 1;
    }

    do
    {
        printf("---MENU---\n");
        printf("1 -- Inserir um valor em uma determinada posicao\n ");
        printf("2 -- Consultar um valor contido em uma determinada posicao\n");
        printf("3 -- Sair\n");
            scanf("%d",&opcao);
        switch (opcao)
        {
            case 1:
                printf("Digite a posicao:\n");
                scanf("%d",&posicao);
                printf("Digite um numero:\n");
                scanf("%d",&valor);
                if(posicao >= 0 && posicao < qtd)
                {
                    point[posicao] = valor;
                }
                else{
                    printf("Posicao invalida\n");
                }
                break;
            case 2:
                achou = 0;
                    printf("Consulte o valor:\n");
                    scanf("%d",&busca);

                    for(int i = 0; i < qtd; i++)
                    {
                        if(busca == point[i])
                        {
                            printf("O numero esta na posicao: %d\n",i);
                            achou = 1;
                        }
                    }
                    if(achou != 1)
                        {
                            printf("Numero nao encontrado.\n");
                        }

                break;
            
            default:
                break;
        }
        
    }while (opcao != 3);

    printf("Saindo...");
    }

    free(point);

    return 0;

}