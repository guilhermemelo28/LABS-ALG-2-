#include <stdio.h>
#include <math.h>

int raizes(float A, float B, float C, float *X1, float *X2);

int main()
{
    float a, b, c;
    float x1, x2;
    int qtd;

    printf("Digite os valores de A, B e C:\n");
    scanf("%f %f %f", &a, &b, &c);

    if (a == 0)
    {
        printf("A deve ser diferente de zero.\n");
        return 0;
    }

    qtd = raizes(a, b, c, &x1, &x2);

    if (qtd == 0)
        printf("Nao existem raizes reais.\n");
    else if (qtd == 1)
        printf("Uma raiz real: %.2f\n", x1);
    else
        printf("Duas raizes reais: X1 = %.2f, X2 = %.2f\n", x1, x2);

    return 0;
}

int raizes(float A, float B, float C, float *X1, float *X2)
{
    float delta = B * B - 4 * A * C;

    if (delta < 0)
        return 0;

    if (delta == 0)
    {
        *X1 = -B / (2 * A);
        return 1;
    }

    *X1 = (-B + sqrt(delta)) / (2 * A);
    *X2 = (-B - sqrt(delta)) / (2 * A);

    return 2;
}