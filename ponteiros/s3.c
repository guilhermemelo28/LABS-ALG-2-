#include <stdio.h>

int meia(int num);

int main()
{
    int num;
    scanf("%d",&num);
    meia(num);
    return 0;
}

int meia( int num)
{
    if ( num <= 0 || num >26)
    {
        return 0;
    }
    for(int i = 0; i < num; i++)
    {
        for(int j = 0; j < i + 1; j++)
        {
            printf("%c",'A' + i);
        }

        printf("\n");
    }
    return 1;
}