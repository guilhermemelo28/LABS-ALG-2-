#include <stdio.h>
#define pi 3.14

void calc_esfera(float r, float *area, float *volume);

int main()
{
    float raio,area,volume;

    printf("Digite o comprimento do raio:\n");
    scanf("%f",&raio);

    calc_esfera(raio,&area,&volume);

    printf("Area: %.2f\n",area);
    printf("Volume: %.2f\n",volume);

    return 0;
}

void calc_esfera(float r, float *area, float *volume)
{
    *area = 4 * pi * (r * r);
    *volume = (4.0/3.0) * pi * (r * r * r);
}