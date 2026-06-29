#include<stdio.h>

int main()
{
    int m1[3][3];

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            printf("Endereco da matriz[%d][%d] = %p\n",i,j,(void*)&m1[i][j]);
        }
    }
}