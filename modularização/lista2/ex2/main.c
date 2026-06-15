#include "mstring.h"
#include <stdio.h>

int main()
{
  char b[50];
  char s[50];
  char copia1[50];
  char copia2[50];
  
  int p, t, respMstrcmp;
  printf("Digite\n");
  fgets(s, 50, stdin);

  printf("Digite\n");
  fgets(b, 50, stdin);

  // tamanho string
  t = mstrlen(s);
  printf("Tamanho da primeira string digitada:%d\n", t);
  p = mstrlen(b);
  printf("Tamanho da segunda string digitada:%d\n", p);

  printf("Copia da primeira string:\n");
  // copia string
  mstrcpy(copia1, s);

  printf("Copia da segunda string:\n");
  mstrcpy(copia2, b);

  // concatenação
  mstrcat(s, b);
  printf("Concatenacao: %s\n", s);

  // mstrcmp
  respMstrcmp = mstrcmp(b,s );
  printf("0 - Se as strings forem iguais.\n1 - se a primeira string vier antes que a segunda string.\nE -1 : se a segunda string vier antes que a primeira string\n");
  printf("Resposta: %d\n", respMstrcmp);

  // mstrupper
  mstrupper(copia1);
  printf("Primeira string maiuscula: %s\n", copia1);

  mstrupper(copia2);
  printf("Segunda string maiuscula: %s\n", copia2);

  // mstrlower
  mstrlower(copia1);
  printf("Primeira string minuscula : %s\n", copia1);
  mstrlower(copia2);
  printf("Segunda string minuscula: %s\n", copia2);

  // qtd vogais
  printf("Quantidade de vogais da primeira string :%d\n", mcount_vogais(copia1));
  printf("Quantidade de vogais da segunda string: %d\n", mcount_vogais(copia2));

  //palindromo
  printf("0- Se nao for palindromo\n 1- Se eh palindromo\n");
  printf("Verificacao da primeira string:%d\n", meh_palindromo(copia1));
  printf("Verificacao da segunda string:%d\n", meh_palindromo(copia2));

  //Remover espaco da string teste:
  mremove_espacos(copia1);
  printf("A primeira string sem espacos : %s\n",copia1);

  mremove_espacos(copia2);
  printf("A segunda string sem espacos:%s\n",copia2);


  return 0;
}

void mremove_espacos(char s[])
{
    int i, j = 0;

    for(i = 0; s[i] != '\0'; i++)
    {
        if(s[i] != ' ')
        {
            s[j] = s[i];
            j++;
        }
    }

    s[j] = '\0';
}