#include "lista.h"
#define true  1
#define false 0
#ifndef _BTRRE_H_
#define _BTREE_H_

typedef struct t_elemento{
	int num;
}t_elemento;

typedef struct s_no{
	struct s_no *esq;
	t_elemento dado;
	struct s_no *dir;
}t_no;

typedef t_no* t_arvore;
typedef unsigned char bool;

t_no *criaNoBT(char a[]);
bool  isVazia(t_no *no);
int comparaBT(t_elemento item1, t_elemento item2);
int comparaBTCriacao(t_elemento item1, t_elemento item2);
t_no *busca(t_arvore raiz, t_elemento dado);
t_no *buscaSetPai(t_arvore raiz, t_elemento dado, t_no **pai);
bool  inserir(t_arvore *raiz, t_elemento item);
bool inserirNaCriacao(t_arvore *raiz, t_elemento item);
void  exibirPreOrdem(t_arvore raiz);
void iguaisBT(DLList *a, t_arvore b);
void inserirBABT(DLList *a, t_arvore *b);
DLList *removerABBT(DLList *a, t_arvore *b);

#endif // _BTRRE_H_
