#include"soma.h"

fracao soma (int n1,int n2,int n3,int n4)
{
    fracao f1,f2,sum;
    
    //para f1:
    f1.denominador = n1;
    f1.numerador = n2;

    //para f2:

    f2.numerador = n3;
    f2.denominador = n4;

    //para soma:

    sum.numerador = (( f1.numerador * f2.denominador) + (f2.numerador * f1.denominador));
    sum.denominador  = (f1.denominador * f2.denominador);

    return sum;






}