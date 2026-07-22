#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n[5];
    int *point;

     point = (int *) malloc(5 * sizeof(int));

    if(point == NULL)
    {
        printf("Erro ao alocar memoria\n");
        return 1;
    }

    printf("Alocacao bem sucedida!! :)\n");

    for(int i = 0; i < 5; i++)
    {
        scanf("%d",&n[i]);
    }

    for(int i = 0; i < 5; i++)
    {
        printf("%d",n[i]);
    }

    free(point);
    return 0;
}