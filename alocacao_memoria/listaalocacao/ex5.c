#include<stdio.h>
#include<stdlib.h>

int main()
{
    int num,tam;
    int *point;

    printf("Digite o tamanho do vetor\n");
    scanf("%d",&tam);

    printf("Digite o numero para ver os multiplos dele:\n");
    scanf("%d",&num);

    point = (int *) malloc(tam * sizeof(int));

    if(point == NULL)
    {
        return 1;
    }

    printf("Multiplos de %d, no vetor de tamanho %d:\n",num,tam);
    for(int i = 0; i < tam;i++)
    {
        
        printf(" %d * %d = %d\n",num,i,num * i);
    }

    free(point);
}