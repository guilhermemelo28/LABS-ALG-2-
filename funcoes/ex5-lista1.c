#include <stdio.h>
#define pi 3.14

float volumeEsfera (int num)
{
    float resp;

    resp = (4.0/3.0) * pi * (num * num * num);

    return resp;
}

int main()
{
    int raio;
    float resposta;

    scanf("%d",&raio);

    resposta = volumeEsfera(raio);

    printf("O volume eh %.2f ",resposta);

}