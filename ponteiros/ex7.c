#include <stdio.h>

void soma(int *a,int *b);

int main()
{
    int v1,v2;
    printf("Digite dois valores aleatorios:\n");
    scanf("%d %d",&v1, &v2);
    soma(&v1,&v2);
    printf("V1 = %d\n",v1);
    printf("V2 = %d\n",v2);
    return 0;
}

void soma(int *a, int *b)
{
   *a += *b;
}