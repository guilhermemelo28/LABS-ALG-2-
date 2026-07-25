#include<stdio.h>

int buscaBinaria(int vet[],int n, int elem);

int main()
{
    int vet[4],elem;
    for(int i = 0; i < 4; i++)
    {
        scanf("%d",&vet[i]);

    }

    for(int i = 0; i < 4; i++)
    {
        printf("%d\t",vet[i]);
    }
    printf("\n");
    scanf("%d",&elem);

    printf("%d",buscaBinaria(vet,4,elem));

    return 0;
}

    int buscaBinaria(int vet[], int n, int elem)
    {
        int esq = 0;
        int dir = n - 1;
        while( esq <= dir)
        {
            int meio = (dir + esq)/2;

            if(vet[meio] == elem )
            {
                return meio;
            }

            if(vet[meio] < elem)
            {
                esq = meio + 1;
            }
            else
            {
                dir = meio - 1;
            }
            
        }
        return -1;
    }