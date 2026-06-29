#include <stdio.h>

void frac(float num, int *inteiro, float *frac);

int main()
{
    float num,vir;
    int inteiro;
    printf("Digite um numero:\n");
    scanf("%f",&num);

    frac(num,&inteiro,&vir);

    printf("A parte inteira:%d\n",inteiro);
    printf("A parte fracionaria:%.2f\n",vir);
    
    return 0;
}

void frac(float num, int *inteiro, float *frac)
{
    *inteiro = (int)num;
    *frac = num - *inteiro;
}
