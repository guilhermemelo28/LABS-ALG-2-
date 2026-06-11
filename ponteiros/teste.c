#include <stdio.h>
int main()
{
    struct teste1
    {
        double a;
        int b;
        char c;
    };
    typedef struct teste1 teste1; 

    struct teste2
    {
        char c;
        double a;
        char b;
        
    };
    typedef struct teste2 teste2;
    
    int resultado1,resultado2;

    resultado1 = sizeof(teste1);
    resultado2 = sizeof(teste2);

    printf("%d\n",resultado1);
    printf("%d\n",resultado2);
    

    
}