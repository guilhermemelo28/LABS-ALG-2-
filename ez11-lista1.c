#include <stdio.h>

float  mediaAluno (float n1, float n2, float n3, char escolha)
{
    float media;
    switch (escolha)
    {
        case 'A':
            media = (n1+n2+n3)/3;
            break;
        
        case 'P':
        media = ((n1*5) + (n2*3) + (n3*2))/(5+3+2);
        break;

        default:
        return 0;
        break;

    }

    return media;
}

int main()
{
    float nota1,nota2,nota3;
    char tipoMedia;
    float media;

    printf("Digite as notas do aluno:");
    scanf("%f %f %f", &nota1,&nota2,&nota3);

    printf("Escolha o tipo de media: 'A' para media aritimetica, 'P' para media ponderada: ");
    scanf(" %c",&tipoMedia);
    

    media = mediaAluno (nota1,nota2,nota3,tipoMedia);

    if (tipoMedia != 'A' && tipoMedia != 'P')
    {
        printf("Nao existe essa opcao");
    }
    else
    {
        printf("O tipo de media escolhido foi: %c. E a media do aluno foi: %2.f", tipoMedia,media);
    }
    return 0;
}