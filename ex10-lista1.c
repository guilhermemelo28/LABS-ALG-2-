#include <stdio.h>

void maior (int num1,int num2)
{
    if (num1 == num2)
    {
        printf("Sao iguais");
    }
    else if ( num1 > num2)
    {
        printf("O %d eh maior que %d",num1,num2);
    }
    else
    {
        printf("O %d eh maior que %d",num2,num1);
    }
    
}

int main()
{
    int n1,n2;
    scanf("%d %d",&n1,&n2);

    maior(n1,n2);

    return 0;
}