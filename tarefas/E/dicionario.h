#ifndef DICIONARIO_H
#define DICIONARIO_H

/* Esse modulo foi inteiramente retirado da pagina
// do professor Paulo Feofiloff, disponivel em:
// http://www.ime.usp.br/~pf/mac0121-2015/tarefas/lista-palavras/index.html 
// Fiz poucas modificacoes, como por exemplo adicionar a busca 
// binaria na funcao inserePalavra. */

/* ------------- Variaveis globais ------------------ */

/* O vetor dic[0..n-1] armazenara o dicionario. O vetor e alocado  
// dinamicamente e tem capacidade para N palavras. */
char **dic;
int n, N;

/* O vetor de caracteres buffer[0..B-1] sera usado para
// armazenamento temporario de uma palavra lida de 'entrada',
// passado como parametro pelo usuario. */
char *buffer;
int B;

/* ------------- Funcoes ------------------ */

/* Essa e a funcao principal que constroi o dicionario. Guarda-o no
// vetor dic[0..n-1] lendo as palavras de 'entrada', passado como
// parametro pelo usuario. Devolve o tempo decorrido no processo. */
double constroiDicionario (FILE *entrada);

/* Le a proxima palavra de entrada e a devolve. Devolve NULL
// se entrada estiver esgotado*/
char *proximaPalavra (FILE *entrada);

/* Dobra a capacidade do vetor de caracteres buffer[0..B-1] */
void expandeBuffer (void);

/* Insere a string pal no vetor dic[0..n-1] e atualiza o valor de n.
// Faz isso com busca binaria, que procura a primeira string maior
// ou igual a pal e a insere em seu lugar, no caso de nao ser igual.
// Quando n vale 0, apenas insere. As variaveis n e dic sao globais.*/
void inserePalavra (char *pal);

/* Dobra o tamanho do vetor dic[0..n-1] */
void expandeDic (void);

/* Imprime o dicionario em 'saida', passado como parametro pelo usuario */
void imprimeDicionario (FILE *saida);

#endif