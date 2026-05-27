#include <stdio.h>

void desenho(int n)
{
    

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            printf("*");
        }
        printf("\n");
    }
    for (int i = n - 1; i >= 1; i--)
    {
        for (int j = 0; j < i; j++)
        {
            printf("*");
        }

        printf("\n");
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    desenho(n);
    return 0;
}