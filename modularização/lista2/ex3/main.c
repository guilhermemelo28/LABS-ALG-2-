#include "conversor.h"
#include <stdio.h>

int main()
{
    char opcao;
    float temperaturaC,conversao, temperaturaF;

    do
    {
        printf("==MENU==\n");
        printf("1- Converter Celsius -> Fahrenheit\n");
        printf("2- COnverter Fahrenheit -> Celcius\n");
        printf(" 0 - Sair\n");

        printf("Digite a temperatura em Celsius:\n");
        scanf("%f",&temperaturaC);

        printf("Digite a temperatura em Fharenheit:\n");
        scanf("%f",&temperaturaF);
        
        printf("Selecione uma opcao:\n");
        scanf("%d",&opcao);

        switch (opcao)
        {
        case 1:
            conversao = celsius_fahrenheit(temperaturaC);
            printf("Temperatura em Celcius: %.2f. Conversao para Fahrenheit: %.2f\n",temperaturaC,conversao);
            break;
        case 2:
            conversao = fahrenheit_celsius(temperaturaF);
            printf("Temperatura em Fahrenheit: %.2f. Conversao para Celcius: %.2f\n",temperaturaF,conversao);
        default:
            break;
        }
    } while (opcao != 0);

    printf("Saindo...");
    
    return 0;
}
