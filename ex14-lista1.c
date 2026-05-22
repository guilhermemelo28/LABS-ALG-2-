#include <stdio.h>

void autonomia(int km, int l)
{
    int consumo;
    consumo = km/l;

    if( consumo < 8)
    {
        printf("Venda o carro!");
    }
    else if ((consumo >= 8) && (consumo <=14))
    {   
        printf("Economico!");
    }
    else
    {
        printf("Super Economico!");
    }
    
}

int main()
{
    int km, litro;

    printf("Digite a distancia da viagem: ");
    scanf("%d",&km);

    printf("Digite quantos litros foram consumidos: ");
    scanf("%d",&litro);

    autonomia(km,litro);

    return 0;
}