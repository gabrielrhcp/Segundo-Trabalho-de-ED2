#include "geral.h"
#include "btree.h"
#define _BTREE_C_

node *criarAB(char a[]){
    node * root = NULL;
    FILE *arquivo;
    int dado;
    arquivo = fopen(a, "r");

    while((fscanf(arquivo,"%d",&dado) != EOF)){
        insertABCriacao(&root, newAB(dado));
    }
    fclose(arquivo);
    return root;
}

void preAB(node * n)
{
	printf("%d ", n->value);
	if(n->l) preAB(n->l);
	if(n->r) preAB(n->r);
}

node * newAB(int value)
{
	node * n = malloc(sizeof(node));
	n->value = value;
	n->l = n->r = NULL;
	return n;
}

void insertABCriacao(node ** root, node * child)
{
	if(!*root)
    {
        *root = child;
	}
	else if(child->value <= (*root)->value)
	{
        insertABCriacao(&(*root)->l, child);
	}
    else
    {
        insertABCriacao(&(*root)->r, child);
    }
}

void insertAB(node ** root, node * child)
{
	if(!*root)
    {
        *root = child;  num_atb++; num_comp++;
	}
	else if(child->value <= (*root)->value)
	{
	    num_comp++;
        insertAB(&(*root)->l, child);
	}
    else
    {
        num_comp++;
        insertAB(&(*root)->r, child);
    }
}

// recursive search of a node
node * searchAB(node * root, int value)
{
	if(root == NULL)
    {
        num_comp++;
        return NULL;
    }
    else if (root->value == value)
    {
        num_comp++;
        return root;
    }
    else if(value > root->value)
    {
        num_comp++;
        searchAB(root->r,value);
    }
    else
    {
        num_comp++;
        searchAB(root->l,value);
    }

}

void iguaisAB(DLList *a, node *b){
    DLNode *aux;
    num_comp+=2;
    if(a != NULL && b != NULL){
        aux = a->first;
        num_atb++;
        while(aux != NULL){
            num_comp++;
            if(searchAB(b,(int)aux->data) != NULL){
                printf("%d ",aux->data);
            }
            num_comp++;
            aux = aux->next;
            num_atb++;
        }
        num_comp++;
    }
}

void inserirBAAB(DLList *a, node *b){
    DLNode *aux;
    num_comp+=2;
    if(a != NULL && b != NULL){
        aux = a->first;
        num_atb++;
        while(aux != NULL){
            num_comp++;
            if(searchAB(b,(int)aux->data) == NULL){
                insertAB(&b, newAB((int)aux->data));
            }
            num_comp++;
            aux = aux->next;
            num_atb++;
        }
        num_comp++;
    }
}

DLList *removerABAB(DLList *a, node *b){
    DLNode *aux;
    DLList *blz = dllCreate(NULL);
    num_comp+=2;
    if(a != NULL && b != NULL){
        aux = a->first;
        num_atb++;
        while(aux != NULL){
            num_comp++;
            if(searchAB(b,(int)aux->data) == NULL){
                dllInsertFirst(blz, aux->data);
            }
            num_comp++;
            aux = aux->next;
            num_atb++;
        }
        num_comp++;
    }
    return blz;
}

