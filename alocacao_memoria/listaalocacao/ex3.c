#include<stdio.h>
#include<stdlib.h>

int main()
{

    int num,par = 0, impar = 0;
    int *point;
    printf("Digite o tamanho do vetor:\n");
    scanf("%d",&num);

    point = (int *) malloc(num * sizeof(int));

    if(point == NULL)
    {
        printf("Erro ao alocar memoria :(\n");
        return 1;
    }

    printf("Memoria alocada com sucesso :)\n");

    for(int i = 0 ; i < num; i++)
    {
        scanf("%d",&point[i]);

        if(point[i] % 2 == 0)
        {
            par++;
        }
        else
        {
            impar++;
        }
    }

    for(int i = 0; i < num; i++)
    {
        printf("%d ",point[i]);
    }

    printf("\nQuantidade de Pares: %d\n Quantidade de Impares: %d\n ",par,impar);

    free(point);
}