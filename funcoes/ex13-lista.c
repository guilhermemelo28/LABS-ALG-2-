#include <stdio.h>


float operacao (float n1,float n2, char simbolo)
{
    float resposta;
    switch (simbolo)
    {
        case '+':
            resposta = n1 + n2;
            break;
        
        case '-':
            resposta = n1 - n2;
            break;
        
        case '*':
            resposta = n1 * n2;
            break;
        
        case '/':
            resposta = n1/n2;
            break;
        
        default: 
            return 0;
    }

    return resposta;
}

int main()
{
    float num1,num2,resposta;
    char opp;

    printf("Escolha dois numeros:");
    scanf("%f %f",&num1,&num2);

    printf("Escolha '+' para soma \n Escola '-' para subtracao \n Escolha '*' para multiplicacao \n Escolha '/' para divisao:\n" );
    scanf(" %c",&opp);

    resposta = operacao(num1,num2,opp);

    printf(" Operacao: %c.\nResultado: %.2f",opp,resposta);
    
    return 0;
}