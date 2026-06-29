#include<stdio.h>

int main()
{
    int v1[5];

    for(int i = 0; i < 5; i++)
    {
        printf("Digite um valor aleatorio:\n");
        scanf("%d",&v1[i]);

        if(v1[i] % 2 == 0)
        {
            printf("Endereco do valor %d: %p\n",v1[i],(void*)&v1[i]);
        }
    }
    return 0;

}