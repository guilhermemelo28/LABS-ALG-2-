#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

void mergesort(int *vet,int l,int r);
void merge(int *vet,int l, int meio, int r);

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

    mergesort(point,0,num - 1);

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

void mergesort(int *vet,int l, int r)
{
    if (l < r)
    {
        int meio = (l + r)/2;

        mergesort(vet,l,meio);//direita
        mergesort(vet,meio + 1, r); //esquerda

        merge(vet,l,meio,r);
    }
}

void merge(int *vet, int l, int meio, int r)
{
    int n1 = meio - l + 1;
    int n2 = r - meio;
    int *temp1 = malloc(n1 * sizeof(int));
    int *temp2 = malloc(n2 * sizeof(int));
    for(int i = 0; i < n1; i++)
    {
        temp1[i] = vet[l + i];    
    }

    for(int i = 0; i < n2 ; i ++)
    {
        temp2[i] = vet[meio + 1 + i];
    }

    int i = 0, j = 0, k = l;

    while (i  < n1 && j < n2 )
    {
        if(temp1[i] < temp2[j])
        {
            vet[k] = temp1[i];
            k++;
            i++;
        }
        else
        {
            vet[k] = temp2[j];
            k++;
            j++;
        }
    }

    while( i < n1)
    {
        vet[k] = temp1[i];
        k++;
        i++;
    }

    while(j < n2)
    {
        vet[k] = temp2[j];
        k++;
        j++;
    }

    free(temp1);
    free(temp2);    
}