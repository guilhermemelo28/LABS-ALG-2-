#include <stdio.h>

float aumentoA (float n);
float aumentoB(float n2);


int main()
{
    float salario,novosalario;
    char opcao;

    printf("-- A = Aumento de 10porcento --\n -- D = Aumento de 8porcento --\n");
    scanf("%f %c",&salario,&opcao);

    switch (opcao)
    {
        
    case 'A':
        novosalario = aumentoA(salario);
        printf("%.2f",novosalario);
        break;
    
    case 'D':
        novosalario = aumentoB(salario);
        printf("%.2f",novosalario);
        break;

    default:
        printf("Opcao invalida\n");
        break;
    }
    return 0;

}

float aumentoA (float n)
{
    float novosalario = n + (n *0.10);
    return novosalario;
}

float aumentoB (float n2)
{
    float nsalario = n2 + (n2 * 0.08);
    return nsalario;
}