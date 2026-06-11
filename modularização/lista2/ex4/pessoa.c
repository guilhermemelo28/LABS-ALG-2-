#include "pessoa.h"
#include <stdio.h>

    pessoa criarPessoa(char nome[], int idade)
    {
        pessoa p;
        p.nome[50] = nome[50];
        p.idade = idade;
        return p;
    }

    void mostrarPessoa(pessoa p)
    {
        printf("Nome da Pessoa:%s\n",p.nome);
        printf("Idade da pessoa:%d\n",p.idade);

    }