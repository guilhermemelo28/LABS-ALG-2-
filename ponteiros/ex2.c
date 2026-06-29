#include <stdio.h>

int main()
{
    int v1,v2;
    if (&v1 >=  &v2)
    {
        printf("Maior: %p\n",&v1);
    }
    else
    {
        printf("Maior: %p\n",&v2);
    }
    return 0;
}