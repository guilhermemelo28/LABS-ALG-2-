//Arquivo com as funções de ordenação e busca.
#include<stdio.h>
#include<stdlib.h>
#include "algoritimos.h"

//ALGORITIMOS DE ORDENAÇÃO:

//Verifica ordenação
int verificaOrdem(int vet[], int tam){
    int i, j;
    for(i = 0; i < (tam - 1) ; i++)
    {
            if(vet[i] > vet[ i + 1])
            {
                return 0;
            }     
    }
    return 1;
}
//INSERTION SORT

void insertionsort(int *vet,int tamvet)
{
    for(int i = 1; i < tamvet; i++)
    {
        int key = vet[i];
        int j = i - 1;
        while(j>= 0 && vet[j] > key)
        {
            vet[j+1] = vet[j];
            j--;
        }
        vet[j+1] = key;
    }
}
//QUICKSORT:
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


//Funções para fazer o MergeSort
void mergesort(int *vet,int l, int r)
{
    if (l < r)
    {
        int meio = (l + r)/2;
        
        mergesort(vet,l,meio);//esquerda
        mergesort(vet,meio + 1, r); //direita
        
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
//Selection Sort:
void selectionsort(int *vet,int tam)
{
    for(int i = 0; i < tam;i++)
    {
        int min = i;

        for( int j = i + 1; j < tam ; j++)
        {
            if(vet[j] < vet[min])
            {
                min = j;
            }
        }
        troca(vet,i,min);
    }
}

void sort(int *vet){

}

void introsort(int *vet){

}

//Função Usada no: Selection Sort, BubbleSort, e Quicksort
void troca(int *vet,int j, int x)
{
    int aux = vet[j];
    vet[j] = vet[x];
    vet[x] = aux;
}

//============================================//

//ALGORITIMOS DE BUSCA

//BUSCA LINEAR
int buscaLinear(int *vet, int tamvetor, int elem)
{
    for (int i = 0; i < tamvetor; i++)
    {
        if (elem == vet[i])
        {
            return i;
        }
    }

    return -1;
}


//BUSCA BINARIA

int buscaBinaria(int *vet, int tamvetor, int elem)
{
    int esq = 0;
    int dir = tamvetor - 1;
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




