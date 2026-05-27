#include <stdio.h>

int secs (int n1, int n2, int n3)
{
    int horas, minutos,total;

    horas = n1 * 3600;
    minutos = n2 * 60;
    total = horas + minutos + n3;

    return total;

}

int main()
{
    int resposta,horas,minutos,segundos;

    printf("Horas:");
    scanf("%d",&horas);

    printf("Minutos:");
    scanf("%d",&minutos);

    printf("Segundos:");
    scanf("%d",&segundos);

    resposta = secs(horas,minutos,segundos);

    printf("Resposta em segundos: %d",resposta);
    return 0;
}