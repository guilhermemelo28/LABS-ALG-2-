#include "operacoes.h"
#include <stdio.h>

int main()
{
    int valorA,valorB,resultado;
    char opcao;

    do
    {
        printf("Digite dois valores inteiros:\n");
        scanf("%d %d",&valorA, &valorB);
        getchar();
        printf("====MENU====\n");
        printf("+ : PARA REALIZAR SOMA\n");
        printf("-: PARA REALIZAR A SUBTRACAO\n");
        printf("*: PARA REALIZAR A MULTIPLICACAO\n");
        printf("/: PARA REALIZAR A DIVISAO\n");
        printf(". : PARA SAIR\n");
        printf("Selecione a operacao:\n");
        scanf("%c",&opcao);

        switch (opcao)
        {
        case '+' :
            
            resultado = soma(valorA,valorB);
            printf("Resultado: %d\n",resultado);
            break;
        
        case '-':
            resultado = subtrai(valorA,valorB);
            printf("Resultado: %d\n",resultado);
            break;
        
        case '*':
            resultado = multiplicacao(valorA,valorB);
            printf("Resultado: %d\n",resultado);
            break;
        
        case '/':
            resultado = divisao(valorA,valorB);
            printf("Resultado: %d\n",resultado);
            break;

        
        default:
            break;
        }
    }while (opcao != '.');
    printf("Saindo...\n");

    return 0;

}