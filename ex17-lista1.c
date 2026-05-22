#include <stdio.h>

int soma (int n1,int n2)
{
    int som = 0;
    if ( n1 >= n2)
    {
        for (int i = n2; i <= n1; i++ )
        {
            som += i;
        }
    }
    else
    {
        for(int i = n1;i <= n2; i++)
        {
            som += i; 
        }
    }
    return som;
}

int main()
{
    int n1,n2,resposta;
    printf("Escolha dois numeros:");
    scanf("%d %d", &n1, &n2);

    resposta = soma(n1,n2);

    printf("Soma dos numeros inteiros entre %d e %d: %d",n1,n2,resposta);
    return 0;
}