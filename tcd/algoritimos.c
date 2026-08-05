//Arquivo com as funções de ordenação e busca.
#include<stdio.h>
#include<stdlib.h>
#include "algoritimos.h"

//Prototipos das funcoes: 

//Algoritimos de Ordenacao:

//Verificacao
int verificaOrdem(int vet[], int tam);

//insertion sort
void insertionsort(int *vet, int tam);

//Bubble sort
void Bubblesort (int *vet, int tam);

//Selection Sort
void selectionsort(int *vet,int tam);

//merge sort
void mergesort(int *vet,int l, int r);
void merge(int *vet, int l, int meio, int r);

//quick sort
void quicksort(int *vet,int l, int r);
int particiona(int *vet,int l ,int r);
int mediana_de_tres(int *vet, int l, int r);

//Intro Sort
void heapify_intervalo(int *vet, int l, int tamanho_heap, int raiz);
void heapsort_intervalo(int *vet, int l, int r);
int calcular_limite_profundidade(int tamanho);
void introsort_recursivo(int *vet, int l, int r, int limite_profundidade);
void introsort(int *vet, int tamanho);

//Usado no Selection Sort, Bubble Sort, Quick Sort e IntroSort
void troca(int *vet,int j, int x);

//============================================//

//ALGORITIMOS DE BUSCA

//Busca Linear
int buscaLinear(int *vet, int tamvetor, int elem);

//Busca Binaria
int buscaBinaria(int *vet, int tamvetor, int elem);

//Acao das funcoes
//ALGORITIMOS DE ORDENAÇÃO:

//Verifica ordenação: Algoritimo para verificar se esta ordenado
int verificaOrdem(int *vet, int tam){
    int i;
    for(i = 0; i < (tam - 1) ; i++)
    {
            if(vet[i] > vet[ i + 1])
            {
                return 0;
            }     
    }
    return 1;
}
//

//INSERTION SORT:
//Recebe vet = vetor que sera ordenado, e tamvet = tamanho do vetor
void insertionsort(int *vet,int tamvet)
{
    for(int i = 1; i < tamvet; i++)  // Percorre os indices do vetor, e comeca no 1 pq o primeiro elemento,sozinho

    {
        int key = vet[i]; // Key = valor que sera inserido na posicao correta 
        int j = i - 1; // Percorre a parte anterior do vetor, da direita para esquerda
        while(j>= 0 && vet[j] > key) // Verifica os elementos anteriores, j>= 0 verifica se estamos dentro do vetor
        // vet[j] > key // Verifica se o elemento anterior eh maior que a chave  que queremos inserir
        // Se for maior que a chave, ele deve ser deslocado para a direita
        {
            vet[j+1] = vet[j];//Copia o elemento maior que a chave uma posicao para a direita   
            j--; //Anda para a esquerda
        }
        //Pos [j + 1] eh a posicao correta aonde devemos colocar nossa chave
        vet[j+1] = key;// Insere o elemento na posicao corret
    }
}
//

//BUBBLE SORT:
//Recebe vet = vetor que vai ser ordenado e tam =  tamanho do vetor

void Bubblesort (int *vet, int tam)
{
    for(int i = 0; i < (tam - 1); i++)// Quantas passagens vao ser feitas pelo vetor 
    {
        int trade = 0; // Indica se ocorreu alguma troca durante a passagem i 

        for(int j = 0; j < (tam-1);j++) //Percorre o vetor comparando os elementos vizinhos , tam - 1 ignora os elementos 
        // que ja foram colocados corretamente no final 
        {
            if(vet[j] > vet[j + 1]) // compara o elemento atual com o proximo
            {
                //Como eles estao na ordem errada
                troca(vet,j,j+1);//Aqui faz a troca 
                trade = 1; //Houve a troca 
            }
            
        }
        if(trade == 0) // Verifica se o vetor esta ordenado 
        {
            break;//Encerra o algoritmo 
        }
    }
}
//

//Selection Sort:
//Recebe vet = vetor que vai ser ordenado e tam =  tamanho do vetor
void selectionsort(int *vet,int tam)
{
    for(int i = 0; i < tam - 1;i++) // i representa aonde o menor elemento restante sera colocado 
    {
        int min = i;//Considera o  i como o indice que tem o menor elemento

        for( int j = i + 1; j < tam ; j++) //Procura um valor menor 
        {
            if(vet[j] < vet[min])// Compara com o menor encontrado
            {
                //Achou
                min = j; // O menor agora esta na posicao j 
            }
        }
        if (min != i) //Verificar se o menor esta em outra posicao
        {
            troca(vet, i, min); //Coloca o menor elemento encontrado na posicao i 
        }
    }
}
//


//MergeSort:
//Essa primeira função merge sort: Divite o vetor em partes menores
//A segunda função merge: Ela junta essas partes em ordem 
//Recebe: Vet = vetor que vai ser ordenado, l = indice inicial do vetor, r = indice final do vetor
void mergesort(int *vet,int l, int r)
{
    if (l < r)// Essa condicao verifica se tem pelo menos dois elementos no intervalo 
    {
        int meio = (l + r)/2; // Calcula a posicao do meio do intervalo 
        
        mergesort(vet,l,meio);//Ordena do meio para esquerda
        mergesort(vet,meio + 1, r); //Ordena do meio para a direita
        
        merge(vet,l,meio,r);//Junta as metades 
    }
}
void merge(int *vet, int l, int meio, int r)
{
    int n1 = meio - l + 1; // calcula o tamanho da metade para a esquerda
    int n2 = r - meio; //calcula o tamanho da metade para a direita 
    int *temp1 = malloc(n1 * sizeof(int)); //cria vetor temporario que armazena a parte da metade para a esquerda
    int *temp2 = malloc(n2 * sizeof(int)); //cria vetor temporario que armazena  a parte da metade para a direita
    for(int i = 0; i < n1; i++)
    {
        temp1[i] = vet[l + i]; // copia metade para a esquerda    
    }
    
    for(int i = 0; i < n2 ; i ++)
    {
        temp2[i] = vet[meio + 1 + i]; // copia metade para a direita 
    }
    
    int i = 0, j = 0, k = l;
    // i percorre temp1, j percorre temp2, k indica aonde escrever o vetor original
    while (i  < n1 && j < n2 ) // laco continua enquanto houver elementos nos dois vetores temporarios 
    {
        if(temp1[i] < temp2[j]) // compara o primeiro elemento ainda nao usado em cada metade, se o valor da esquerda for menor  
        {
            //valor da esquerda eh o menor

            vet[k] = temp1[i]; //coloca no vetor original
            k++; // avanca uma posicao no vetor original
            i++; // avanca uma posicao em temp1
        }
        else
        {
            //valor da direita eh o menor
            vet[k] = temp2[j];//coloca no vetor original
            k++; // avanca uma posicao no vetor original
            j++; // avanca uma posicao em temp2
        }
    }
    
    while( i < n1) // copia os elementos restantes da esquerda, caso temp2 termina primeiro, copia o que sobrou em temp1
    {
        vet[k] = temp1[i];//coloca no vetor original
        k++; // avanca uma posicao no vetor original
        i++;// avanca uma posicao em temp1
    }

    while(j < n2) // copia os elementos restantes da direita, caso temp1 termina primeiro, copia o que sobrou em temp2 
    {
        vet[k] = temp2[j];//coloca no vetor original
        k++;//avanca uma posicao no vetor original
        j++;//avanca uma posicao em temp2
    }
    
    free(temp1);//libera a memoria alocada do vetor temp1
    free(temp2);// libera a memoria alocada  do vetor temp2   
}
//


//QUICKSORT:
//Recebe vet = vetor que vai ser ordenado
//L = primeiro indice  do intervalo
//R = ultimo indice do intervalo

void quicksort(int *vet,int l, int r)
{

    if (l < r) //Isso verifica se no intervalo tem mais de um elemento
    {
        int pivo = particiona(vet,l,r);// Particiona o vetor (coloca os menores elementos a esquerda, e coloca os maiores elementos a direita)
        //Seleciona a posicao definitiva do pivo, Estrutura vetor pos particiona: menores | pivo | maiores
        
        quicksort(vet,l,pivo - 1); //Ordena o lado esquerdo
        quicksort(vet,pivo + 1, r); //Ordena o lado direito  

        // IMPORTANTE: O PIVO NAO PARTICIPA NOVAMENTE PORQUE JA ESTA ORDENADO!
    }
}
int particiona(int *vet,int l ,int r)
{
    mediana_de_tres(vet, l, r); //Escolhe o pivo com a mediana de tres 
    int pivo = r; //Guarda o indice do pivo e nao o valor
    
    int i = l - 1; // Marca  o final da regiao dos elementos menores que  pivo
    int j = l;// Indice que percorre o vetor 

    for( j = l; j < r;j++) //o laco vai de l ate r porque na posicao r esta o pivo
    {
        if (vet[j] < vet[pivo]) //Se o elemento atual for menor que o pivo ele deve ficar na regiao da esquerda
        {
            //Aumenta a regiao dos menores antes de trocar, por isso incrementamos o i antes da troca
            troca(vet,++i,j);
        }
    }
    
    troca(vet,++i,r); //Coloca o pivo na posicao definitiva, incrementamos o i primeiro porque o i ainda apontado para o ultimo elemento
    //menor do que o pivo, ++i avanca para a primeira posicao depois dos menores

    return i; // retorna a posicao do pivo
}


int mediana_de_tres(int *vet, int l, int r) 
{
    if (r - l < 2) // verifica se existem tres posicoes 
    {
        //nao existe tres posicoes diferentes para comparar
        return r; //mantem o ultimo como o pivo 
    }

    int meio = l + (r - l) / 2; //calcula o indice central

    if (vet[l] > vet[meio]) // ordena o primeiro e o meio
    {
        troca(vet, l, meio); 
    }
    //depois da condicao vet[l] <= vet[meio]


    if (vet[l] > vet[r]) // ordena primeiro e o ultimo
    {
        troca(vet, l, r);
    }
    //depois da condicao vet[l] <= vet[r]

    if (vet[meio] > vet[r]) // ordena meio e o ultimo
    {
        troca(vet, meio, r);
    }
    //depois da condicao vet[meio] <= vet[r]

    troca(vet, meio, r);// leva a mediana do primeiro, do meio e do ultimo para o final 

    return r;// retorna o indice do pivo 
}
//


//Introsort:
//Recebe Vet e o tamanho
void introsort(int *vet, int tamanho)  
{
    if (tamanho <= 1)
    {
        return;
    }
    //Calcula o profundida das divisões 
    int limite_profundidade = calcular_limite_profundidade(tamanho);
    //Aqui verifica o tamanho do intervalo, verfica se a profundidade acabou e diminui o limite
    introsort_recursivo(vet, 0, tamanho - 1, limite_profundidade);
    //Termina a ordenacao com o InsertionSort
    insertionsort(vet, tamanho);
}

//Recebe Vet, l = posicao inicial do intervalo atual, r = posiciao final do intervalo atual
//limite_profundida = Quantidade maxima de niveis de particionamento que o QuickSort pode realizar naquele caminho
void introsort_recursivo(int *vet, int l, int r, int limite_profundidade) 
{
    while (r - l + 1 > 16)//Verifica se o intervalo ainda eh grande 
    {
        if (limite_profundidade == 0)// Verifica se o algoritimo com a logica do QuickSort ficou muito profundo,
                                    // se chegar a 0 significa que o algoritmo fez divisoes demais
        {
            heapsort_intervalo(vet, l, r);//Aqui o introsort para de usar o algoritmo com a logica do QuickSort e comeca a usar o HeapSort
            return;
        }

        limite_profundidade--;//Diminui o Limite 

        int posicao_pivo = particiona(vet, l, r);//Parte em que comeca a ocorrer a logica do QuickSort acontece aqui

        //IntroSort comeca a ordenar os dois lados(Aqui eh o Quick Sort dentro do IntroSort)

        if (posicao_pivo - l < r - posicao_pivo)//Primeiro ordenar o Menor Lado (Se o lado esquerdo for menor):
        {
            introsort_recursivo(vet, l, posicao_pivo - 1, limite_profundidade);
            l = posicao_pivo + 1;//Algoritmo continua no lado direito do pivo
            //Ordena o Lado esquerdo recursivamente, e continua no lado direito usando o While
        }
        else //Lado direito menor
        {
            introsort_recursivo(vet, posicao_pivo + 1, r, limite_profundidade);
            r = posicao_pivo - 1;//Algoritmo continua no lado esquerdo do Pivo  
        }
    }
}

//Recebe o tamanho do vetor
int calcular_limite_profundidade(int tamanho)
{
    int logaritmo = 0;

    while (tamanho > 1)
    {
        tamanho /= 2;
        logaritmo++;
    }

    return 2 * logaritmo; //Como o quickSort quando faz divisôes equilibradas,a profundidade que ele gera é proxima de log(tam), 
                          //colocamos 2*log(n), para dar equilibrio, usamos o 2 para que quando as divisôes nâo forem perfeitas
                          // o algoritmo com a logica do QuickSort continua trabalhando, e quando passa desse limite passa para o HeapSort
}

//Recebe vet que esta sendo ordenado, l indice onde comeca a parte que o HeapSort deve ordenar
//r = Indice  onde termina a parte que o HeapSort deve ordenar
void heapsort_intervalo(int *vet, int l, int r)
{
    int tamanho = r - l + 1; //Calcula o tamanho do intervalo, quantos elementos tem entre r e l, + 1 eh importante porque r e l fazem parte do intervalo

    if (tamanho <= 1)//Ver se o intervalo esta ordenado
    {
        return;// Se o intevalo tiver nenhum  ou 1 elemento, quer dizer que ja esta ordenado
    }

    for (int i = tamanho / 2 - 1; i >= 0; i--)// Percorre todos os elementos que possuem filho, comeca no ultimo pai: tam/ 2 - 1
    {
        heapify_intervalo(vet, l, tamanho, i);//Organiza cada pai, verificar se o pai eh maior que os filhos 
    }

    for (int i = tamanho - 1; i > 0; i--)//Coloca os elementos na posicao correta 
    {
        troca(vet, l, l + i);//Troca a raiz com o ultimo elemento do Heap, ultimo elemento do heap atual esta em: l + i
        heapify_intervalo(vet, l, i, 0); //Diminui o tamanho do heap, LEMBRANDO o tamanho enviado eh i!
    }
}
//Recebe vet que contem o heap, l = indice real onde o intervalo do heap comeca no vetor, tamanh0_heap = quantidade de elementos que ainda fazem
//parte do heap. raiz = posicao relativa aonde que o heapify deve verificar
void heapify_intervalo(int *vet, int l, int tamanho_heap, int raiz)
{
    while (1)//Laco criado que continua ate o heap estar correto
    {
        int maior = raiz;//Consideramos que a raiz eh o maior elemento
        int esquerda = 2 * raiz + 1;//Posicao relativa do filho esquerdo
        int direita = 2 * raiz + 2;//Posicao relativa do Filho direito

        //Compara com o Filho esquerdo. 1- Verifica se ele existe em (esquerda < tamanho_heap). 2- Verifica se o valor do filho esquerdo
        //eh maior que o valor que consideramos ser o maior.
        if (esquerda < tamanho_heap && vet[l + esquerda] > vet[l + maior])
        {
            maior = esquerda;// Se o filho esquerdo for maior que o valor, entao ele vai ser o nosso maior.
        }

        //Compara com o Filho direito. 1- Verifica se ele existe em (direita < tamanho_heap). 2- Verifica se o valor do filho direito
        //eh maior que o valor que consideramos ser o maior.
        if (direita < tamanho_heap && vet[l + direita] > vet[l + maior])
        {
            maior = direita; // Se o filho direito for maior que o valor, entao ele vai ser o nosso maior.
        }

        if (maior == raiz)//Verifica se eh necessario fazer a troca 
        {
            break; //Encerra o Laco, ou seja a propriedade do Heap esta correta: Pai maior que os filhos
        }

        troca(vet, l + raiz, l + maior);//Raiz esta menor que algum filho. Por isso troca de posicação com o maior deles
        //Somamos L porque raiz e maior sao posicoes relativas ao intervalo

        raiz = maior; // Continua na posicao aonde o elemento desceu
    }
} 
//

//Função Usada no: Selection Sort, BubbleSort, Quicksort e no IntroSort
//Recebe Vet = vetor de elementos, j = posicao do primeiro valor, x = posicao do segundo valor
void troca(int *vet,int j, int x)
{
    int aux = vet[j]; //Auxiliar criado para armezar o primeiro valor que queremos guardar 
    vet[j] = vet[x];//Troque entre O primeiro valor e o segundo valor, ou seja, O primeiro valor == segundo valor, mas perdemos o primeiro valor
    vet[x] = aux;//Agora aqui acontece a troca do Segundo valor com o primeiro valor(armezado pelo o auxiliar).
}

//============================================//

//ALGORITIMOS DE BUSCA: Ambos Algoritmos recembem vet = vetor em que sera realizada a busca, tamVetor = tamanho do vetor
// e elem = elemento que vai ser buscado

//BUSCA LINEAR
int buscaLinear(int *vet, int tamvetor, int elem)
{
    for (int i = 0; i < tamvetor; i++) //Percorre todo o vetor comecando em 0
    {
        if (elem == vet[i]) //Achou o elemento
        {
            return i; //Retorna a posicao do elemento
        }
    }

    return -1; //Nao achou o elemento
}


//BUSCA BINARIA

int buscaBinaria(int *vet, int tamvetor, int elem)
{
    int esq = 0; //Indice mais a esquerda do intervalo atual
    int dir = tamvetor - 1; //Indice mais a direita do intervalo atual
    while( esq <= dir)//Continua enquanto o intervalo existir 
    {
        int meio = (dir + esq)/2;//calcula o indice central

        if(vet[meio] == elem )//verfica se encontrou o elemento no meio
        {
            //encontrou o elemento
            return meio;//retorna a posicao do meio
        }

        if(vet[meio] < elem)// se vet[meio] for menor que o elemento que estamos procurando, logo o elemento que estamos procurando esta a esquerda
        {
            esq = meio + 1; //descartamos tudo que esta a esquerda e o meio
        }
        else //se vet[meio] for maior que o elemento que estamos procurando, logo o elemento que estamos procurando esta a direita 
        {
            dir = meio - 1;//descartamos tudo que esta a direita e o meio 
        }
        
    }
    return -1; //nao achou o elemento
}




