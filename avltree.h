#include "lista.h"
#ifndef _AVLTREE_H_
#define _AVLTREE_H_

typedef struct node_tree{
	int key; // valor
	struct node_tree *left;
	struct node_tree *right;
	int height;
}Node;

Node* createAvlTree(char a[]);
int max(int a, int b);
int height(Node *N);
Node *newNodeCriacao(int key);
Node *rightRotateCriacao(Node *y);
Node *leftRotateCriacao(Node *x);
Node *newNode(int key);
Node *rightRotate(Node *y);
Node *leftRotate(Node *x);
int getBalance(Node *N);
Node *insert(Node *node, int key);
Node *insertCricao(Node *node, int key);
Node *minValueNode(Node *node);
void preOrder(Node *root);
int comparaAVL(int a, Node *b);
void iguaisAVL(DLList *a, Node *b);
void inserirBAAVL(DLList *a, Node *b);
DLList *removeBAAVL(DLList *a, Node *b);

#endif // _AVLTREE_H_
