#include <stdio.h>

void ler_notas (float *n1, float *n2);
void medias (float n1, float n2, float *mediasimples,float *mediaponderada);


int main()
{
    float n1,n2;
    float msimples,mponderada;

    printf("Digite as notas:\n");
    scanf("%f %f",&n1,&n2);

    ler_notas(&n1,&n2);
    medias(n1,n2,&msimples,&mponderada);

    printf("Nota 1: %.2f\n Nota 2:%.2f\n Media Simples: %.2f\n Media Ponderada:%.2f",n1,n2,msimples,mponderada);

}

void ler_notas (float *n1, float *n2)
{
    *n1 = *n1;
    *n2 = *n2;
}

void medias (float n1, float n2, float *mediasimples,float *mediaponderada)
{
    *mediasimples = (n1 + n2 )/ 2;
    *mediaponderada = (n1 + (n2 * 2))/ 3;
}
