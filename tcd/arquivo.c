#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arquivo.h"

// Função para carregar arquivos e ler os numeros presentes nele
int carregar_arquivo(const char *nome, int **vetor){
    int numero; //Armazena temporariamente cada número lido no arquivo
    int i = 0;  //Contador de elementos lidos e índice atual do vetor
    int *temp; //Ponteiro auxiliar para validar a realocação do memória com segurança
    int tamvetor = 1000; // variavel usada para realocar o tamanho do vetor

    // Abri o arquivo informado apenas para a leitura ("r")
    FILE *arquivo = fopen(nome , "r");
    // Verifica se houve falha ao abrir o arquivo (ex: arquivo não existe)
    if (arquivo == NULL)
    {
        printf("Erro\n");
        return -1;// Retorna -1 para indicar erro de abertura
    }

    if (*vetor != NULL) {
        free(*vetor);
        *vetor = NULL;
    }

    *vetor = (int *) malloc(tamvetor * sizeof(int));
    if (*vetor == NULL) {
        printf("Erro ao alocar memoria inicial!\n");
        fclose(arquivo);
        return -1;
    }
    
    // Loop de leitura: lê um número inteiro por vez enquanto houver dados válidos no arquivo
    while (fscanf(arquivo, "%d", &numero) == 1)
    {  
        // Se a quantidade de itens lidos atingir ou ultrapassar a capacidade atual
        if (i >= tamvetor)
        {
            // Expandi o tamanho do vetor apontado por *vetor multiplicando a capacidade por 10
            temp = (int *) realloc(*vetor , tamvetor * 10 * sizeof(int));

            // Se o realloc falhar (falta de RAM), encerra com erro sem perder o ponteiro original
            if (temp == NULL)
            {
                printf("Erro ao alocar\n");
                fclose(arquivo); //Fecha o ponteiro do arquivo antes de sair
                return -1;
            }
            else{
                // Atualiza o ponteiro do vetor com o novo endereço retornado pelo realloc
                *vetor = temp;
            }
            // Atualiza a variável para controlar a capacidade do vetor
            tamvetor *= 10;
        }
        
        // Atribui o número lido na posição 'i' do vetor
        (*vetor)[i] = numero;
        i++; // Incrementa a quantidade total de números armazenados
    }

    // Fecha o arquivo após concluir a leitura
    fclose(arquivo);

    // Retorna o total de elementos que foram lidos e salvos com sucesso
    return i;
}

//Recebe o nome do arquivo que voce quer colocar, o vetor que contem os numeros salvos e o tamanho do vetor
int salvar_vetor(char *nomearquivo, int *vet, int tamanho)
{
    
    if(strstr(nomearquivo, ".txt") == NULL)//Verifica se o nome do arquivo que voce colocou tem ".txt" a funcao strstr procura uma sequencia
    //de caracteres dentro de nomearquivo
    {
        //se voce nao colocou ".txt"
        strcat(nomearquivo, ".txt"); //a funcao strcat ela concatena uma string na outra, ou seja, ela adciona uma string no final da outra
        //nesse caso ele vai colocar ".txt" depois do nome do arquivo
    }

    FILE *arquivo = fopen(nomearquivo, "w"); //Aqui declara o ponteiro do arquivo e abre ele, fopen recebe o nome do arquivo e o modo
    //como esse arquivo vai ser criado: "w" de write
    
    if (arquivo == NULL) //Se o ponteira nao conseguir criar/abrir o arquivo
    {
        return -1; //Arquivo nao pode ser aberto
    }

    for (int i = 0; i < tamanho; i++) //Percorre todas as posicoes validas do vetor
    {
        fprintf(arquivo, "%d\n", vet[i]); //Escreve os elementos do vetor no arquivo
    }

    fclose(arquivo);//Fecha o arquivo depois que todos os elementos foram gravados no arquivo

    return 0;
}