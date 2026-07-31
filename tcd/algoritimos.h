//Biblioteca dos algoritimos de busca e ordenação utlizados no TCD

//ALGORITIMOS DE ORDENAÇAO

//Algoritimo para verificar se o vetor esta ordenado

int verificaOrdem(int vet[], int tam);

//insertion sort
void insertionsort(int *vet, int tam);

//quick sort
void quicksort(int *vet,int l, int r);
int particiona(int *vet,int l ,int r);
int mediana_de_tres(int *vet, int l, int r);

//merge sort
void mergesort(int *vet,int l, int r);
void merge(int *vet, int l, int meio, int r);

//Bubble sort
void Bubblesort (int *vet, int n);

//Selection Sort
void selectionsort(int *vet,int tam);

//Usado no Selection Sort, Bubble Sort, Quick Sort
void troca(int *vet,int j, int x);

//============================================//

//ALGORITIMOS DE BUSCA

//Busca Linear
int buscaLinear(int *vet, int tamvetor, int elem);

//Busca Binaria
int buscaBinaria(int *vet, int tamvetor, int elem);

