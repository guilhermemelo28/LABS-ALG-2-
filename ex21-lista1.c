#include <stdio.h>

void desenho(int n)
{
    for (int i = 0; i <= n; i++)
    {

        for(int j = 0; j < i; j++ )
        {
            printf("!");
        }
        printf("\n");
    }
}

int main()
{
    int qntd;
    printf("Digite a quantidade de '!': ");
    scanf("%d",&qntd);

    desenho(qntd);
    return 0;
}