#include "pessoa.h"
#include <stdio.h>

    pessoa criarPessoa(char nome[], int idade)
    {
        pessoa p;
        int i = 0;
        while(nome[i] != '\0')
        {
            p.nome[i] = nome[i];
            i++;
        }

        p.nome[i] = '\0'; 
            p.idade = idade;
            return p;
    }

    void mostrarPessoa(pessoa p)
    {
        printf("Nome da Pessoa:%s\n",p.nome);
        printf("Idade da pessoa:%d\n",p.idade);

    }