#include<stdio.h>

void troca (int *a, int *b);
int main()
{
    int v1,v2;
    printf("Digite dois valores:\n");
    scanf("%d %d",&v1, &v2);

    troca(&v1,&v2);

    printf("V1 = %d\n",v1);
    printf("V2 = %d\n",v2);
    return 0;

}
void troca(int *a, int *b)
{
    int point = *a;
    *a = *b;
    *b = point;    
}