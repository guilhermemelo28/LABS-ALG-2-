#include<stdio.h>
#include<stdlib.h>

int alocMemoria (int n, char **point);
void stringSemvogal (char c[],int i);
int main()
{
    int tamString,verifica;
    char *point;
    printf("Digite o tamanho da string:\n");
    scanf("%d",&tamString);
    getchar();

    
    verifica =  alocMemoria(tamString, &point);

    if(verifica == 0)
    {
        fgets(point,tamString + 1, stdin);
        
        stringSemvogal(point,tamString);

        point[tamString] = '\0';

        free(point);
    }

    else
    {
        printf("Nao foi possivel alocar a memoria");
    }

    return 0;

}


int alocMemoria(int n, char **point)
{
    *point = (char*) malloc((n + 1) * sizeof(char));

    if(*point == NULL)
    {
        return 1;
    }

    return 0;

}

void stringSemvogal (char c[],int s)
{
    for(int i = 0; i < s; i++)
    {
        if(c[i] == 'a' || c[i] == 'e'|| c[i] == 'i' || c[i] == 'o' || c[i] == 'u')
        {
            c[i] = ' ';
        }
    }
    printf("%s",c);
}