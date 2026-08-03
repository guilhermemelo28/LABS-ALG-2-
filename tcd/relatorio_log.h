typedef struct{
        char log1[100];
        char log2[100];
        char log3[100];
        char log4[100];
        char log5[100];
        char log6[100];
        char log7[100];
        char log8[100];
    }Log;
void registrar_log(const Log *relatoriolog);
int copiavetor(const int *vet, int **vettemp, int tamanho);