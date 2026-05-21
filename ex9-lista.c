#include <stdio.h>
#define pi 3.141592

double volume (float altura, float raio)
{
    double resposta;

    resposta = pi *(raio * raio) * altura;
    
    return resposta;

}

int main ()
{
    float alt, r;
    double resp;

    printf("Digite o valor da altura e do raio respectivamente: ");
    scanf("%f %f", &alt,&r);

    resp = volume(alt,r);

    printf("O volume eh %lf",resp);

    return 0;
}