#include<stdio.h>

void dobro(int *a);

int main()
{
    int v1[5];

    for (int i = 0; i < 5; i++)
    {
        printf("Digite um valor:\n");
        scanf("%d",&v1[i]);
        dobro(&v1[i]);
        printf("Valor[%d] = %d\n ",i + 1,v1[i]);
    }
}
void dobro(int *a)
{
    int dobro = *a * 2;
    *a = dobro;
}