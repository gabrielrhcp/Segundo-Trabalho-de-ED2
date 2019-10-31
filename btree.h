#include "lista.h"
#ifndef _BTRRE_H_
#define _BTREE_H_

typedef struct node{
	struct node * l, * r;
	int value;
} node;

node *criarAB(char a[]);
node * newAB(int value);
node * searchAB(node * root, int value);
void insertAB(node ** root, node * child);
void preAB(node * n);
void iguaisAB(DLList *a, node *b);
void inserirBAAB(DLList *a, node *b);
DLList *removerABAB(DLList *a, node *b);


#endif // _BTRRE_H_
