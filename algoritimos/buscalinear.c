#include <stdio.h>
#include<stdlib.h>
// s eh o tamanho do vetor
void buscaLinear(int vet[], int s, int elem)
{
    for (int i = 0; i < s; i++)
    {
        if (elem == vet[i])
        {
            printf("O num %d esta na posicao %d",elem,i);
        }
    }


}

int main()
{
    int num;
    int *point;
    int elem;

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
    printf("NUmero para buscar:\n");
    scanf("%d",&elem);

    buscaLinear(point, num, elem);
    return 0;
}