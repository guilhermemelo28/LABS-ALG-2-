#include <stdio.h>

int somaALg(int num)
{

    int soma = 0;

    while (num > 0)
    {
        soma += (num % 10);
        num /= 10;
    }

    return soma;

}


int main()
{
    int num,resposta;

    scanf("%d",&num);

    if (num > 0)
    {
        resposta = somaALg(num);
        printf("Soma dos algs: %d",resposta);
    }

    else  printf("Numero invalido");
    

    return 0;
}