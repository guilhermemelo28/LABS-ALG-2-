#include<stdio.h>
#include<windows.h>
#include<stdlib.h>

void Bubblesort(int *vet,int n);
void troca(int vet[],int j, int x);

int main()
{
    LARGE_INTEGER frequency;
    LARGE_INTEGER inicio,fim;
    double elapsedtime;

    QueryPerformanceFrequency(&frequency);
    QueryPerformanceCounter(&inicio);

    int num;
    int *point;

    printf("Digite o tamanho do vetor:\n");
    scanf("%d",&num);

    point = (int *) malloc(num * sizeof(int));

    if(point == NULL){
        return 1;
    }

    for(int i = 0 ; i < num; i++){
        scanf("%d",&point[i]);
    }

    Bubblesort(point,num);

    printf("Vetor ordenado:\n");

    for(int i = 0; i < num ; i++)
    {
        printf("%d\n",point[i]);
    }

    free(point);
    
    QueryPerformanceCounter(&fim);
    elapsedtime = (fim.QuadPart - inicio.QuadPart) * 1000.0 / frequency.QuadPart;
    printf("- Time: %.16lf ms\n",elapsedtime);
    
    return 0;
}
    
void Bubblesort (int *vet, int n)
{
    for(int i = 0; i < (n - 1); i++)
    {
        int trade = 0;
        for(int j = 0; j < (n-1);j++)
        {
            if(vet[j] > vet[j + 1])
            {
                troca(vet,j,j+1);
                trade = 1;
            }

        }
        if(trade == 0)
        {
            break;
        }
    }
}

void troca(int vet[],int j, int x)
{
    int aux = vet[j];
    vet[j] = vet[x];
    vet[x] = aux;
}