#include <stdio.h>

int fatorial(int n1)
{
    int resposta = 1;
    
    for (int i = 1; i <= n1; i ++)
    {
        resposta *= i;
    }
    return resposta; 
}

int main()
{

    int n1; 
    printf("Escolha um numero: ");
    scanf("%d",&n1);

    printf("Fatorial de %d: %d",n1,fatorial(n1));

    return 0;
}