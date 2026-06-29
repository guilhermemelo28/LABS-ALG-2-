#include <stdio.h>

int main()
{
    //variaveis
    int num1;
    float num2;
    char carac;
    // ponteiros
    int *point1 = NULL;
    float *point2 = NULL;
    char *point3 = NULL;

    printf("Digite o valor inteiro:\n");
    scanf("%d",&num1);
    printf("\nDigite o valor real:\n");
    scanf("%f",&num2);
    printf("Digite um caracter aleatorio:\n");
    scanf(" %c",&carac);

    point1 = &num1;
    point2 = &num2;
    point3 = &carac;

    printf("Inteiro: %d\n",(*point1 + 1));
    printf("Real: %.2f\n",(*point2 + 1.5));
    printf("Char:%c\n",(*point3 - 32));

}