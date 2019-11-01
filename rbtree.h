#include "lista.h"
#define RUB 0
#define NEG 1
#define N_MAX 1027
#ifndef _RBTREE_H_
#define _RBTREE_H_

typedef struct tipoNo tipoNo;
typedef struct tipoArvore tipoArvore;
void criarArvoreRB(tipoArvore *arvore, char a[]);
tipoNo* noAvo(tipoNo *n);
tipoNo* noIrmao(tipoNo *n);
tipoNo* noTio(tipoNo *n);
tipoNo* noAvoCriacao(tipoNo *n);
tipoNo* noIrmaoCriacao(tipoNo *n);
tipoNo* noTioCriacao(tipoNo *n);
tipoNo* rotacaoEsquerda(tipoNo* raiz, tipoNo* n);
tipoNo* rotacaoEsquerdaCriacao(tipoNo* raiz, tipoNo* n);
tipoNo* rotacaoDireita(tipoNo* raiz, tipoNo* n);
tipoNo* rotacaoDireitaCriacao(tipoNo* raiz, tipoNo* n);
int verificaCor(tipoNo* n);
int verificaCorCriacao(tipoNo* n);
tipoNo* balanceamentoCaso1(tipoNo* raiz, tipoNo* n);
tipoNo* balanceamentoCaso2(tipoNo* raiz, tipoNo* n);
tipoNo* balanceamentoCaso3(tipoNo* raiz, tipoNo* n);
tipoNo* balanceamentoCaso4(tipoNo* raiz, tipoNo* n);
tipoNo* balanceamentoCaso5(tipoNo* raiz, tipoNo* n);
tipoNo* balanceamentoCaso1Criacao(tipoNo* raiz, tipoNo* n);
tipoNo* balanceamentoCaso2Criacao(tipoNo* raiz, tipoNo* n);
tipoNo* balanceamentoCaso3Criacao(tipoNo* raiz, tipoNo* n);
tipoNo* balanceamentoCaso4Criacao(tipoNo* raiz, tipoNo* n);
tipoNo* balanceamentoCaso5Criacao(tipoNo* raiz, tipoNo* n);
tipoNo* noNovoCriacao(int dado);
tipoNo* noNovo(int dado);
tipoNo* inserirElemento(int numero, tipoNo *raiz);
tipoNo* inserirElementoCriacao(int numero, tipoNo *raiz);
void inserirArvore(int numero, tipoArvore* arvore);
void inserirArvoreCriacao(int numero, tipoArvore* arvore);
tipoNo* buscarElemento(int numero, tipoNo *raiz);
tipoNo* buscarNaArvore(int numero, tipoArvore arvore);
void preOrderRB(tipoNo *root);
void igualRB(DLList *a, tipoNo *b);
void inserirBARB(DLList *a, tipoNo *b);
DLList *removerBARB(DLList *a, tipoNo *b);

#endif // _RBTREE_H_
