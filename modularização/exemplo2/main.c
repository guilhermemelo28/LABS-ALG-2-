#include <stdio.h>
#include "soma.h"

int main()
{
    int n1,n2,n3,n4;
    fracao receba;

    scanf("%d %d %d %d",&n1,&n2,&n3,&n4);

    receba = soma(n1,n2,n3,n4);

    printf("%d/%d",receba.numerador,receba.denominador);
    return 0;
}