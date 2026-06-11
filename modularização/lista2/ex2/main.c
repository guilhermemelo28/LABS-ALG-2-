#include "mstring.h"
#include <stdio.h>

int main()
{
    char s[10];
    int t ;
    printf("Digite\n");
    scanf("%s",s);

    t = mstrlen(s);

    printf("%d",t);

    return 0;
}