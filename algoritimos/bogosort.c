#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>

void bogosort(int vet[], int tam);
int issorted( int vet[], int tam);
void embaralha(int vet[],int tam);
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
    srand(time(NULL));
    
    printf("Digite o tamanho do vetor:\n");
    scanf("%d",&num);
    
    point = (int *) malloc(num * sizeof(int));
    
    if(point == NULL){
        return 1;
    }
    
    for(int i = 0 ; i < num; i++){
        scanf("%d",&point[i]);
    }
    
    bogosort(point,num);
    
    for(int i = 0; i < num ; i++){
        printf("%d\n",point[i]);
    }
    free(point);
    QueryPerformanceCounter(&fim);
    elapsedtime = (fim.QuadPart - inicio.QuadPart) * 1000.0 / frequency.QuadPart;
    printf("- Time: %.16lf ms\n",elapsedtime);
    
    return 0;
}


void bogosort(int vet[],int tam)
{
    while(!issorted(vet,tam))
    {
        embaralha(vet,tam);
    }
}

int issorted(int vet[],int tam)
{
    for(int i = 0; i < (tam - 1);i++)
    {
        if(vet[i] > vet [i + 1])
        {
            return 0;
        }
    }
    return 1;
}

void embaralha(int vet[], int tam)
{
    

    for(int i = 0; i < (tam - 1);i++)
    {
        int rd = rand() % tam;
        troca(vet,i,rd);
    }
}

void troca(int vet[],int j, int x)
{
    int aux = vet[j];
    vet[j] = vet[x];
    vet[x] = aux;
}