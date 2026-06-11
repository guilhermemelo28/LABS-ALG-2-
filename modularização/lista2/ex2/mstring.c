#include "mstring.h"

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
    
    return contador;
}
