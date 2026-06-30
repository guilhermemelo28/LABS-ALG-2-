#include <stdio.h>

void arvore(int *r);
int main()
{
    int ramos;
    scanf("%d",&ramos);
    arvore(&ramos);
    return 0;
}
void arvore(int *r)
{
    for(int i = 1; i <= *r; i++)
    {
        for(int j = 1; j <= *r - i; j++ )
        { 
            printf(" ");
        }
        for(int j = 1; j <= 2 * i - 1 ; j++)
        {
            printf("%c",'A' + i - 1);
        }
        printf("\n");
    }
}    