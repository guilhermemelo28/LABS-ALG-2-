#include<stdio.h>

int main()
{
    float v1[10];
    for(int i = 0; i < 10; i++)
    {
        printf("Endereco do vetor[%d] : %p\n",i,(void*)&v1[i]);

    }
}