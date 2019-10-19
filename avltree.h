#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef _AVLTREE_H_
#define _AVLTREE_H_

typedef struct node_tree Node;
Node* createAvlTree(int dados);
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
void iguais(Node *a, Node *b);
void compara(int a, Node *b);

#endif // _AVLTREE_H_
