//RESOLUÇÃO PROVINHA DE ONTEM

#include <stdio.h>

int main ()

{
        //ex 1
        int fumaca, temperatura;

        //ex 2
        int numero, resto, verifica;

        //ex3
        char vet[101], max = 1, atual = 1;

        int i,q = 3;


        for ( i = 0; i < (q + 1); i++){


        switch ( i + 1)
        {
        case  1:
            //questao de if else
            printf("Questao %d: \n", i + 1);

            printf("Digite o nivel de fumaca: ");
            scanf("%d",&fumaca);
            printf("\n");

            printf("Digite a temperatura em graus celcius: ");
            scanf("%d",&temperatura);
            printf("\n");

            if((temperatura < 40) && (fumaca < 20))
            {

                printf("Seguro!\n");

            }

            else if (((temperatura <= 60) && (temperatura >= 40)) || ((fumaca >= 20) && (fumaca <= 50) ))
            {

                printf(" Alerta!\n");
                
            } 
            else if ((temperatura > 50) && (fumaca > 40))
            {

                printf("Critico!\n");
            
            }

            else 
            {

                printf("Perigo!\n");
                
            }

            

            break;
            case 2:

            //loop de repeticao
            printf("Questao %d: \n", i + 1);
            printf("Numero:\n");
            scanf("%d",&numero);

            while (numero > 0){
            
                resto = numero % 10;

                if ((numero % resto) == 0){
                    numero /= 10;
                    verifica = 1;
                }
                else{
                    verifica = 0;
                    break;
                }
                numero /= 10;

            }

            printf((verifica == 1) ? "SIM\n" : "NAO\n");


            break;



            case 3:
            //string e vetor
            printf("Questao %d: \n", i + 1);

                printf("Digite um string:\n");
                scanf("%s",vet);

                    for (i = 1; vet[i] != '\0'; i++){

                    if ( vet[i] == vet[i-1]){
                        atual++;
                    }else {
                        max = (atual > max) ? atual : max;
                        atual = 1;
                    }
                }

                    max = (atual > max) ? atual : max;
                    printf("%d\n",max);


            break;

            default:
            printf("Acabou as questoes :( ");

            break;
        }


        }

return 0;
}