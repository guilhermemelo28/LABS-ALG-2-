#include<stdio.h>
#include<stdlib.h>
int main(){
    
    int num;
    int *point;

    printf("Digite o tamanho do vetor:\n");
    scanf("%d",&num);

    point = (int *) malloc(num * sizeof(int));

    if(point == NULL){
        printf("Erro ao alocar memoria :(\n");
        return 1;
    }

    printf("Memoria alocada com sucesso :)\n");
    for(int i = 0 ; i < num; i++){
        scanf("%d",&point[i]);
    }

    for(int i = 0; i < num ; i++){
        printf("%d",point[i]);
    }
    free(point);
    return 0;

}