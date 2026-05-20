#include <stdio.h>


int ehprimo(int x)
{

    if (x < 2)
    {
        return 0;
    }

    for (int i = 2; i < x; i++)
    {

        if (x % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int qtdprimo(int n)
{
    int primo = 0;

    for (int i = 2; i <= n; i++)
    {

        if (ehprimo(i))
        {
        primo++;
        }
    }

    return primo;
}

int main()
{
    int resposta, valor;
    printf("Digite o valor: ");
    scanf("%d", &valor);

    resposta = qtdprimo(valor);

    printf("A qtd de primo(s) eh (sao): %d", resposta);

    return 0;
}