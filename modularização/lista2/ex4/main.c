#include <stdio.h>
#include "pessoa.h"

int main()
{
    char nome[50];
    int idade;

    printf("Digite seu nome:\n");
    scanf("%s",&nome);

    printf("Digite sua idade:\n");
    scanf("%d",&idade);

    mostrarPessoa(criarPessoa(nome,idade));
    return 0;
}