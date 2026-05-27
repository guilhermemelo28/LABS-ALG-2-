#include <stdio.h>

int dobro (int num)
{
    return 2 * num;
}

int main()
{
    int numero, resultado;

    printf("Digite o valor:");
    scanf("%d",&numero);

    resultado = dobro(numero);

    printf("O dobro de %d eh %d", numero, resultado);
}