#include <stdio.h>

int verifica (int l1, int l2, int l3)
{
    int vef = 0;

    if ( ((l1 + l2) > l3) && ( (l2 + l3) > l1) && ((l1 + l3) > l2))
    {
        vef = 1;
        
    }
    else
    {
        vef = 0;
    }

    return vef;

}

void tipoTriangulo (int l1, int l2, int l3)
{
    if((l1 == l2) == l3)
    {
        printf("O triangulo eh escaleno");
    }
    else if ( (l1 == l2)|| (l2 == l3)|| (l3==l1))
    {
        printf("O triangulo eh isosceles");
    }
    else
    {
        printf("O triangulo eh escaleno");
    }
}

int main ()
{
    int l1,l2,l3; 
    int vdd;

    printf("Digite os lados do seu triangulo: ");
    scanf("%d %d %d",&l1 ,& l2, &l3);

    vdd = verifica(l1,l2,l3);

    if (vdd == 1)
    {
        tipoTriangulo(l1,l2,l3);
    }

    else
    {
        printf("O triangulo nao existe");
    }

    return 0;
}