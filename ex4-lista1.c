#include <stdio.h>

int perfeito (int n)
{
    for ( int i = 0; i <= n; i++ )
    {
        if( i * i == n)
        {
            return 1;
        }
    } 
}

int main()
{
    int num, resposta;
    scanf("%d",&num);

    resposta = perfeito(num);

    if(resposta == 1)
    {
        printf("O %d eh um quadrado perfeito",num);
    }
    else
    {
        printf("O %d nao eh um quadrado perfeito",num);
    }
    return 0;
}