#include <stdio.h>

float conversao (float celcius)
{
    float convertida;

    convertida = celcius * (9.0/5.0) + 32.0;

    return convertida;
}

int main ()
{
    float tempCelcius, resposta;

    printf("Digite a temperatura em Celcius:");
    scanf("%f",&tempCelcius);

    resposta = conversao(tempCelcius);

    printf("Em Celcius: %.2f.\n Em Farenheit: %.2f \n",tempCelcius,resposta);

    return 0;
}