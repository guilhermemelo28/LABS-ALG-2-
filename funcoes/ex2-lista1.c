#include <stdio.h>

void dataExtenso(int dia, int mes, int ano) {
    char meses[12][20] = {
        "janeiro",
        "fevereiro",
        "marco",
        "abril",
        "maio",
        "junho",
        "julho",
        "agosto",
        "setembro",
        "outubro",
        "novembro",
        "dezembro"
    };

    printf("%d de %s de %d\n", dia, meses[mes - 1], ano);
}

int main() {
    int dia, mes, ano;

    printf("Digite o dia: ");
    scanf("%d", &dia);

    printf("Digite o mes: ");
    scanf("%d", &mes);

    printf("Digite o ano: ");
    scanf("%d", &ano);

    dataExtenso(dia, mes, ano);

    return 0;
}