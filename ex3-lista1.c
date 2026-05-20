#include <stdio.h>

int verifica (int num)
{
    if ( num == 0)
    {
        
        return 0;
    }
    else if (num > 0)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

int main()
{
    int num, resultado;

    printf("Digite o numero:");
    scanf("%d",&num);

    resultado = verifica(num);
    
    printf("%d",resultado);
    
    return 0;
}