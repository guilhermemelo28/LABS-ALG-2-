#include <stdio.h>
// s eh o tamanho do vetor
int buscaLinear(char vet[], int s, char elem)
{
    for (int i = 0; i < s; i++)
    {
        if (elem == vet[i])
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    char vet[3], elem;
    int resultado;

    scanf("%s", vet);
    fflush(stdin); // limpar buffer
    scanf("%c", &elem);

    resultado = buscaLinear(vet, 3, elem);
    printf("%d", resultado);
}