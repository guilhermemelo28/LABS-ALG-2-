#include <stdio.h>

int exponenciacao (int n1, int n2)
{
    int resultado = 1;
    for(int i = 0; i < n2; i++)
    {
        resultado *= n1;

    }  
    return resultado;

}

int main()
{
    int base,exponencial;

    printf("Diga a base e o expoente respectivamente: ");
    scanf("%d %d", &base, &exponencial);

    printf("Resultado %d",exponenciacao(base,exponencial));

    return 0;
}