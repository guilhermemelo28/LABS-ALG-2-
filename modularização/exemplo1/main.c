#include <stdio.h>
#include "fracao.h"

int main()
{
    fracao receba;
    int n1,n2;

    scanf("%d %d",&n1, &n2);

    receba = generate(n1, n2);

    printf("%d / %d\n", receba.numerador, receba.denominador);
    return 0;

}