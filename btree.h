#define true  1
#define false 0
#ifndef _BTRRE_H_
#define _BTREE_H_

typedef struct s_no t_no;
typedef t_no* t_arvore;
typedef unsigned char bool;
t_no *criaNoBT(int i);
bool  isVazia(t_no *no);
int comparaB(int item1, int item2);
t_no *busca(t_arvore raiz, int dado);
t_no *buscaSetPai(t_arvore raiz, int dado, t_no **pai);
bool  inserir(t_arvore *raiz, int item);
bool  remover(t_arvore *raiz, int item);
void  esvaziar(t_arvore *raiz);
void  exibirPreOrdem(t_arvore raiz);

#endif // _BTRRE_H_
