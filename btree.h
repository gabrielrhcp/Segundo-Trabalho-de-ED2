#define true  1
#define false 0
#ifndef _BTRRE_H_
#define _BTREE_H_

typedef struct s_no t_no;
typedef t_no* t_arvore;
typedef struct t_elemento t_elemento;
typedef unsigned char bool;
t_no *criaNoBT(int i);
bool  isVazia(t_no *no);
int comparaBT(t_elemento item1, t_elemento item2);
t_no *busca(t_arvore raiz, t_elemento dado);
t_no *buscaSetPai(t_arvore raiz, t_elemento dado, t_no **pai);
bool  inserir(t_arvore *raiz, t_elemento item);
bool  remover(t_arvore *raiz, t_elemento item);
void  esvaziar(t_arvore *raiz);
void  exibirPreOrdem(t_arvore raiz);
void iguaisBT(t_arvore a, t_arvore b);
t_no *inserirBABT(t_arvore a, t_arvore b);
t_no *removerABBT(t_arvore a, t_arvore b);

#endif // _BTRRE_H_
