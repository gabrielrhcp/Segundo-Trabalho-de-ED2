#include "lista.h"
#ifndef _AVLTREE_H_
#define _AVLTREE_H_

typedef struct node_tree Node;
Node* createAvlTree(char a[]);
int max(int a, int b);
int height(Node *N);
Node *newNode(int key);
Node *rightRotate(Node *y);
Node *leftRotate(Node *x);
int getBalance(Node *N);
Node *insert(Node *node, int key);
Node *minValueNode(Node *node);
Node *deleteNode(Node *root, int key);
void preOrder(Node *root);
int compara(int a, Node *b);
void iguaisAVL(DLList *a, Node *b);
void inserirBA(DLList *a, Node *b);
DLList *removeBA(DLList *a, Node *b);

#endif // _AVLTREE_H_
