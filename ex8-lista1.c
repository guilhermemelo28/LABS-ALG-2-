#include <stdio.h>
#include <math.h>

double hip (double cateto1, double cateto2)
{
    double resposta;

    resposta = sqrt(pow(cateto1,2) + pow (cateto2,2));

    return resposta;

}

int main()
{
    double a,b,resposta;

    printf("Digite os valores dos catetos: ");
    scanf("%lf %lf",&a,&b);

    resposta = hip (a,b);

    printf("O valor da hipostenusa eh: %lf.",resposta);
    return 0;
}
