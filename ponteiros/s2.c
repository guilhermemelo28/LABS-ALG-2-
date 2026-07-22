#include <stdio.h>

void vogal(char *n);
int main()
{
    char p[100];
    fgets(p, 100, stdin);

    vogal(p);

    return 0;
}

void vogal(char *n)
{
    char *leitura = n;
    while (*leitura != '\0')
    {
        if (*leitura == 'a' || *leitura == 'e' || *leitura == 'i' || *leitura == 'o' || *leitura == 'u')
        {
            *leitura = '*';
        }
        leitura++;
    }
    printf("Novo : %s", n);
}