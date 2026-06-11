#include"operacoes.h"
int soma(int a, int b)
{
    int resultado;

    resultado = a + b;

    return resultado;
}

int subtrai(int a, int b)
{
    int resultado;

    resultado = a - b;

    return resultado;
}

int multiplicacao(int a,int b)
{
    int resultado;

    resultado = a * b;

    return resultado;
}

int divisao(int a, int b)
{
    int resultado;
    if(b != 0)
    {
    resultado = a/b;
    }
    
    return resultado;
}