#include <stdio.h>

void desenhaLinha (int qntd)
{

    for ( int i = 0; i < qntd; i++)
    {
        printf("=");
    }
}

int main()
{
    int qntd;
    printf("Qtd de sinais '=': ");
    scanf("%d",&qntd);

    desenhaLinha(qntd);
    return 0;
}