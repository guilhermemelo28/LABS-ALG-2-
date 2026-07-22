#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

void quicksort(int *vet,int l,int r);
int particiona(int *vet,int l, int r);
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

    point = (int*) malloc(num * sizeof(int));

    if(point == NULL){
        printf("Nao alocou\n");
        return 1;
    }

    for(int i = 0 ; i < num; i++){
        scanf("%d",point+i);
    }

    quicksort(point,0,num - 1);

    printf("Vetor ordenado:\n");

    for(int i = 0; i < num ; i++)
    {
        printf("%d ",point[i]);
    }

    free(point);
    
    QueryPerformanceCounter(&fim);
    elapsedtime = (fim.QuadPart - inicio.QuadPart) * 1000.0 / frequency.QuadPart;
    printf("- Time: %.16lf ms\n",elapsedtime);
    
    return 0;
}

void quicksort(int *vet,int l, int r)
{
    if (l < r)
    {
        int pivo = particiona(vet,l,r);

        quicksort(vet,l,pivo - 1);
        quicksort(vet,pivo + 1, r);
    }
}

int particiona(int *vet,int l ,int r)
{
    int pivo = r; // posso fazer uma funcao para selecionar pivo
    
    int i = l - 1;
    int j = l;

    for( j = l; j < r;j++)
    {
        if (vet[j] < vet[pivo])
        {
            troca(vet,++i,j);
        }
    }

    troca(vet,++i,r);
    return i;
}

void troca(int vet[],int j, int x)
{
    int aux = vet[j];
    vet[j] = vet[x];
    vet[x] = aux;
}