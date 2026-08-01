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
//

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
//

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
    mediana_de_tres(vet, l, r);
    int pivo = r; 
    
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

int mediana_de_tres(int *vet, int l, int r)
{
    if (r - l < 2)
    {
        return r;
    }

    int meio = l + (r - l) / 2;

    if (vet[l] > vet[meio])
    {
        troca(vet, l, meio);
    }

    if (vet[l] > vet[r])
    {
        troca(vet, l, r);
    }

    if (vet[meio] > vet[r])
    {
        troca(vet, meio, r);
    }
    troca(vet, meio, r);

    return r;
}
//

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
//

//Bubble Sort: 
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
//

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
//

//Introsort:
void heapify_intervalo(int *vet, int l, int tamanho_heap, int raiz)
{
    while (1)
    {
        int maior = raiz;
        int esquerda = 2 * raiz + 1;
        int direita = 2 * raiz + 2;

        if (esquerda < tamanho_heap && vet[l + esquerda] > vet[l + maior])
        {
            maior = esquerda;
        }

        if (direita < tamanho_heap && vet[l + direita] > vet[l + maior])
        {
            maior = direita;
        }

        if (maior == raiz)
        {
            break;
        }

        troca(vet, l + raiz, l + maior);

        raiz = maior;
    }
}

void heapsort_intervalo(int *vet, int l, int r)
{
    int tamanho = r - l + 1;

    if (tamanho <= 1)
    {
        return;
    }

    for (int i = tamanho / 2 - 1; i >= 0; i--)
    {
        heapify_intervalo(vet, l, tamanho, i);
    }

    for (int i = tamanho - 1; i > 0; i--)
    {
        troca(vet, l, l + i);
        heapify_intervalo(vet, l, i, 0);
    }
}

int calcular_limite_profundidade(int tamanho)
{
    int logaritmo = 0;

    while (tamanho > 1)
    {
        tamanho /= 2;
        logaritmo++;
    }

    return 2 * logaritmo;
}

void introsort_recursivo(int *vet, int l, int r, int limite_profundidade)
{
    while (r - l + 1 > 16)
    {
        if (limite_profundidade == 0)
        {
            heapsort_intervalo(vet, l, r);
            return;
        }

        limite_profundidade--;

        int posicao_pivo = particiona(vet, l, r);

        if (posicao_pivo - l < r - posicao_pivo)
        {
            introsort_recursivo(vet, l, posicao_pivo - 1, limite_profundidade);
            l = posicao_pivo + 1;
        }
        else
        {
            introsort_recursivo(vet, posicao_pivo + 1, r, limite_profundidade);
            r = posicao_pivo - 1;
        }
    }
}

void introsort(int *vet, int tamanho)
{
    if (tamanho <= 1)
    {
        return;
    }

    int limite_profundidade = calcular_limite_profundidade(tamanho);

    introsort_recursivo(vet, 0, tamanho - 1, limite_profundidade);

    insertionsort(vet, tamanho);
}
//

//Função Usada no: Selection Sort, BubbleSort, Quicksort e no IntroSort
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




