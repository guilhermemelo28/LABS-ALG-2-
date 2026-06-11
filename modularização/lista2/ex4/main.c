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

    mostrarPessoa(criarPessoa(nome[50],idade));
    return 0;
}