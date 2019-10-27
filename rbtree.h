#define RUB 0
#define NEG 1
#define N_MAX 1027
#ifndef _RBTREE_H_
#define _RBTREE_H_

typedef struct tipoNo tipoNo;
typedef struct tipoArvore tipoArvore;
void criarArvoreRB(tipoArvore *arvore, int i);
tipoNo* noAvo(tipoNo *n);
tipoNo* noIrmao(tipoNo *n);
tipoNo* noTio(tipoNo *n);
tipoNo* rotacaoEsquerda(tipoNo* raiz, tipoNo* n);
void rotacaoEsquerdaRR(tipoNo **x);
tipoNo* rotacaoDireita(tipoNo* raiz, tipoNo* n);
void rotacaoDireitaRR(tipoNo **x);
int verificaCor(tipoNo* n);
tipoNo* balanceamentoCaso1(tipoNo* raiz, tipoNo* n);
tipoNo* balanceamentoCaso2(tipoNo* raiz, tipoNo* n);
tipoNo* balanceamentoCaso3(tipoNo* raiz, tipoNo* n);
tipoNo* balanceamentoCaso4(tipoNo* raiz, tipoNo* n);
tipoNo* balanceamentoCaso5(tipoNo* raiz, tipoNo* n);
tipoNo* noNovo(int dado);
tipoNo* inserirElemento(int numero, tipoNo *raiz);
void inserirArvore(int numero, tipoArvore* arvore);
tipoNo* buscarElemento(int numero, tipoNo *raiz);
tipoNo* buscarNaArvore(int numero, tipoArvore arvore);
tipoNo* maiorDosMenores(tipoNo *raiz);
tipoNo* menorDosMaiores(tipoNo *raiz);
tipoNo* conserta(tipoNo** raiz, tipoNo* no);
tipoNo* transplante(tipoNo **raiz, tipoNo* no,tipoNo* noAux);
tipoNo* removerElemento(int numero, tipoNo *raiz);
void removerDaArvore(int numero, tipoArvore *arvore);
int maior(int numeroA, int numeroB);
int calculaAltura(tipoNo *raiz);
void preOrderRB(tipoNo *root);
void igualRB(tipoNo *a, tipoNo *b);
tipoNo* inserirBARB(tipoNo *a, tipoNo *b);
tipoNo* removerBARB(tipoNo *a, tipoNo *b);

#endif // _RBTREE_H_
