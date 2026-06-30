#include <stdio.h>
void concatenar(char *n);
int main()
{
    char nome[50];

    fgets(nome,50,stdin);

    concatenar(nome);
    return 0;
}

void concatenar (char *n)
{
    char *leitura = n;
    char *escrita = n;

    while(*leitura != '\0')
    {
        if(*leitura != ' ')
        {
            *escrita = *leitura;
            escrita++;
        }
        leitura++;
    }
    *escrita = '\0';

    printf("Concatenacao: %s",n);

}