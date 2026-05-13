#include <stdio.h>
    //para ser primo ele  deve ser SOMENTE  divisel por 1 e ele mesmo
    //par = 2k
    // impar = 2k + 1 

    int ehprimo(int x)
    {

        if (x < 2){
            return 0;
        }
        
        for (int i = 2; i <= x; i ++){

            if (x % i == 0){
                return 0;
            }
        }
        return 1;

    }

    int qtdprimo (int n)
    {
        int primo = 0;

        for (int i = 2; i < n; i ++)
        {

            if (ehprimo(i))
            {
                primo ++;
            }
        }
        
        return primo;
    }

    int main ()
    {
        int resposta,valor;
        printf("Digite o valor: ");
        scanf("%d",&valor);

        resposta = qtdprimo(valor);

        printf("A qtd de primo(s) eh (sao): %d",resposta);

        return 0;
    }