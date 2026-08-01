# Sistema de Ordenação e Busca em C

Projeto acadêmico desenvolvido em linguagem C para carregar números inteiros de um arquivo de texto, realizar buscas, ordenar os dados por diferentes algoritmos, salvar o vetor ordenado e registrar as operações executadas em um arquivo de log.

## AUTORES
-AUGUST0 APARECIDO COSTA - MATRICULA: 32521BSI016;
-EMILIO DA SILVA MACHADO - MATRICULA: 32521BSI012;
-GUILHERME MOURA DE MELO - MATRICULA: 32521BSI008;
-NATANAEL RIBEIRO DE ALCANTARA - MATRICULA: 322521BSI002;

## Funcionalidades

O programa possui um menu interativo com as seguintes funcionalidades:

- Carregamento de números inteiros a partir de um arquivo ".txt";
- Busca linear;
- Busca binária;
- Verificação automática de ordenação antes da busca binária;
- Ordenação utilizando cinco algoritmos diferentes;
- Exibição do vetor ordenado no terminal;
- Salvamento do vetor ordenado em um novo arquivo;
- Registro automático das operações e tempo de execução dos algoritimos em um arquivo de log;
- Alocação dinâmica de memória para arquivos com diferentes quantidades de números.

## Algoritmos implementados
 
### Algoritmos de busca

#### Busca Linear

Percorre o vetor desde o início até encontrar o elemento procurado. Pode ser utilizada mesmo quando o vetor não está ordenado.

#### Busca Binária

Compara o elemento procurado com o elemento central do vetor e elimina metade do espaço de busca a cada repetição.

> **Importante:** a busca binária somente funciona corretamente quando o vetor está ordenado. O programa verifica essa condição antes de realizar a busca.

### Algoritmos de ordenação

#### Insertion Sort

Percorre o vetor e insere cada elemento na posição correta dentro da parte que já foi ordenada. É eficiente para vetores pequenos ou quase ordenados.

#### Bubble Sort

Compara elementos vizinhos e realiza trocas quando eles estão fora de ordem. A implementação possui uma otimização que interrompe o algoritmo caso nenhuma troca seja realizada durante uma passagem.

#### Selection Sort

Procura o menor elemento da parte ainda não ordenada e o coloca na próxima posição correta do vetor.

#### Merge Sort

Divide o vetor em partes menores, ordena cada parte recursivamente e depois combina as partes em ordem crescente. Utiliza vetores auxiliares durante a intercalação.

#### Quick Sort

Seleciona um pivô, divide os elementos entre menores e maiores que o pivô e ordena as duas partes recursivamente. O projeto utiliza a técnica da mediana de três para melhorar a escolha do pivô.


## Complexidade dos algoritmos

| Algoritmo      | Melhor caso | Caso médio | Pior caso | Memória auxiliar    |
|---|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|---|
| Insertion Sort | O(n)        | O(n²)      | O(n²)     | O(1)                |
| Bubble Sort    | O(n)        | O(n²)      | O(n²)     | O(1)                |
| Selection Sort | O(n²)       | O(n²)      | O(n²)     | O(1)                |
| Merge Sort     | O(n log n)  | O(n log n) | O(n log n)| O(n)                |
| Quick Sort     | O(n log n)  | O(n log n) | O(n²)     | O(log n), em média  |
| Busca Linear   | O(1)        | O(n)       | O(n)      | O(1)                |
| Busca Binária  | O(1)        | O(log n)   | O(log n)  | O(1)                |

## Estrutura do projeto

./tcd
|── crescente_1000.txt
|── crescente_10000.txt
|── crescente_100000.txt
|── crescente_1000000.txt
|── decrescente_1000.txt
|── decrescente_10000.txt
|── decrescente_100000.txt
|── decrescente_1000000.txt
|── desordenado_1000.txt
|── desordenado_10000.txt
|── desordenado_100000.txt
|──desordenado_1000000.txt
├── main.c
├── algoritimos.c
├── algoritimos.h
├── arquivo.c
├── arquivo.h
├── relatorio_log.c
├── relatorio_log.h
└── README.md

### Descrição dos arquivos

-"./tcd": pasta do trabalho, contendo todos os arquivos necessários;
- "main.c": contém o menu principal e controla o fluxo do programa;
- "algoritimos.c": contém as implementações dos algoritmos de ordenação e busca;
- "algoritimos.h": contém os protótipos das funções de ordenação e busca;
- "arquivo.c": contém as funções para carregar e salvar arquivos;
- "arquivo.h": contém os protótipos das funções de manipulação de arquivos;
- "relatorio_log.c": contém a função responsável pelo registro de logs;
- "relatorio_log.h": contém o protótipo da função de log;
- "log_sistema.txt": é criado automaticamente durante a execução do programa;
- "README.md": documentação do projeto.

## Carregar Arquivo 
## Atenção ao nome do arquivo

Ao carregar um arquivo, digite o nome completo, incluindo a extensão:

decrescente_1000.txt

O arquivo deve conter somente o nome dele pois ele está presente na pasta corrente que é tcd não contendo subpastas.

## Como utilizar o programa

### 1. Carregar o arquivo

Ao iniciar o programa, selecione:

1- Carregar Arquivo de texto

Depois, informe o nome do arquivo:

por exemplo:

decrescente_1000.txt

Deve-se carregar um arquivo para que o programa possa executar as outras opções como por exemplo a opção 2 e 3.

### 2. Buscar um elemento

Selecione:

2- Busca Elemento

Depois escolha:

1- Busca Linear
2- Busca Binaria

Em seguida, informe o número que deseja procurar.

A busca linear pode ser utilizada em qualquer vetor. A busca binária exige que os dados tenham sido ordenados anteriormente.

### 3. Ordenar os dados

Selecione:

3- Ordenar dados

Escolha um dos algoritmos:

1- Insertion Sort
2- Bubble Sort
3- Selection Sort
4- Merge Sort
5- Quick Sort
6- Extra
7- Sair

Após a ordenação, os números são mostrados no terminal, um por linha.

### 4. Salvar o vetor ordenado

Depois de selecionar uma opção de ordenação, o programa pergunta se o vetor deve ser salvo:

1- Sim
2- Nao

Ao escolher "1" , informe um nome para o arquivo:

decrescente_1000.txt

A extensão ".txt" é adicionada automaticamente quando não foi digitada. Portanto, o arquivo será salvo como:

decrescente_1000.txt

Cada número é gravado em uma linha separada.

### 5. Encerrar o programa

No menu principal, selecione:

5- Sair

A memória utilizada pelo vetor é liberada antes do encerramento.

## Sistema de logs

O programa registra automaticamente em forma de relatorio as principais informações operacionais no arquivo e o tempo de execução dos algoritimos de ordenação e de busca:

log_sistema.txt

O arquivo é criado na pasta em que o programa está sendo executado. Os novos registros são adicionados ao final do arquivo, sem apagar os registros anteriores.

Cada linha contém:

- Data e hora;
- Nível ou categoria do evento;
- Módulo do sistema;
- Mensagem descritiva.

Exemplo:

2026-07-31 13:40:20 [INICIO] [INICIALIZACAO] CODIGO INICIALIZADO
2026-07-31 13:40:25 [ARQUIVO] [SUCESSO] ARQUIVO ENCONTRADO
2026-07-31 13:40:30 [ORDENACAO] [OPCAO] SELECIONADO QUICK SORT
2026-07-31 13:40:35 [FINALIZACAO] [FINAL] ARQUIVO ENCERRADO


A opção "4- Gerar relatorio(Log)" registra uma nova ocorrência no log. Entretanto, o arquivo de log já é criado e atualizado automaticamente durante toda a execução.

## Exemplo completo de utilização

Arquivo "decrescente_1000.txt":

1000
999
998
997
996
995
994
993
992
991
990
...


Execução:

===MENU===
1- Carregar Arquivo de texto.
2- Busca Elemento (Linear ou Binario)
3- Ordenar dados: Insert, Bubble, Selection, Merge, Quick, Extra
4- Gerar relatorio(Log)
5- Sair

Digite a opcao
1

Digite o nome do arquivo no qual voce quer carregar:

por exemplo:

decrescente_1000.txt

Sucesso ao carregar arquivos

Em seguida, selecione a opção "3" e escolha o Quick Sort. O resultado será:

1
2
3
4
5
6
7
8
9
10
...
