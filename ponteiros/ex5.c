#include <stdio.h>

void trocamaior( int *a, int *b);

int main()
{
    int v1,v2;
    printf("Digite dois valores aleatorios:\n");
    scanf("%d %d",&v1, &v2);
    trocamaior(&v1,&v2);
    printf("V1 = %d\n",v1);
    printf("V2 = %d\n",v2);
    return 0;
}

void trocamaior(int *a, int *b)
{
    if (*a < *b)
    {
        int point1 = *b;
        *b = *a;
        *a = point1;
    }
    
}
