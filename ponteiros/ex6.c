#include<stdio.h>

void dobro (int *a, int *b);

int main()
{  
    int v1,v2;
    printf("Digite dois valores aleatorios:\n");
    scanf("%d %d",&v1, &v2);

    dobro(&v1,&v2);
    printf("V1 = %d\n",v1);
    printf("V2 = %d\n",v2);
    return 0;
}

void dobro(int *a, int *b)
{
    int dobroA = (*a) * 2;
    int dobroB = (*b) * 2;
    *a = dobroA;
    *b = dobroB;
}
