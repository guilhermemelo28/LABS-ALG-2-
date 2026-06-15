#include "mstring.h"
#include <stdio.h>

int mstrlen(char s[])
{
    int contador = 0;
    int vdd = 0;
    int i = 0;
    
    while( vdd == 0)
    {
        if( s[i] != '\0')
        {
            contador++;
        }
        else
        {
            vdd = 1;
        }
        i++;
    }
    
    return contador - 1;
}

void mstrcpy(char dest[], char orig[])
{
    int i = 0;
    while(orig[i] != '\0')
        {
            dest[i] = orig[i];
            i++;
        }
        dest[i] = '\0';

    printf("Copia: %s\n",orig);

}

void mstrcat(char dest[], char orig[])
{
    int i = 0;
    int j = 0;

    while (dest[i] != '\0') {
        i++;
    }

    while (orig[j] != '\0') {
        dest[i] = orig[j];
        i++;
        j++;
    }

    dest[i] = '\0';
}

int mstrcmp(char a[], char b[])
{
    int i = 0;

    while (a[i] != '\0' && b[i] != '\0')
    {
        if (a[i] < b[i])
            return -1;

        if (a[i] > b[i])
            return 1;

        i++;
    }

    if (a[i] == '\0' && b[i] == '\0')
        return 0;

    if (a[i] == '\0')
        return -1;

    return 1;
}

void mstrupper(char s[])
{
    int i;
    for(i = 0 ; s[i] != '\0'; i++)
    {
        if(s[i] >= 'a' && s[i] <= 'z')
        {
            s[i] = s[i] - 32;
        }
    }
}

void mstrlower(char s[])
{
    int i;

    for(i = 0; s[i] != '\0'; i++)
    {
        if(s[i] >= 'A' && s[i] <= 'Z')
        {
            s[i] += 32;
        }
    }
}

int mcount_vogais(char s[])
{
    int i;
    int vogal = 0;
    for(int i = 0; s[i] !='\0'; i++)
    {
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'o' || s[i] == 'i' || s[i] == 'u')
        {
            vogal++;
        }
    }
    return vogal;
}

int meh_palindromo(char s[])
{
    int i;
    int tam = mstrlen(s);

    for(i = 0; i < tam / 2; i++)
    {
        if(s[i] != s[tam - 1 - i])
        {
            return 0; 
        }
    }

    return 1; 
}
