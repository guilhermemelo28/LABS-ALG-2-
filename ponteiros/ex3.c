#include <stdio.h>

int main()
{
    int valor1, valor2;

    printf("Digite dois valores aleatorios:\n");
    scanf("%d %d",&valor1,&valor2);
    if (&valor1 >=  &valor2)
    {
        printf("Maior endereco:%p\n",(void*)&valor1);
        printf("Conteudo: %d\n",valor1);
    }
    else
    {
        printf("Maior endereco:%p\n",(void*)&valor2);
        printf("Maior: %d\n",valor2);
    }
    return 0;
}