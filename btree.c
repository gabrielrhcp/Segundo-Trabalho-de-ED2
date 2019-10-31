#include "geral.h"
#include "btree.h"
#define _BTREE_C_

node *criarAB(char a[]){
    node * root = NULL;
    FILE *arquivo;
    int dado;
    arquivo = fopen(a, "r");

    while((fscanf(arquivo,"%d",&dado) != EOF)){
        insertAB(&root, newAB(dado));
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

// recursive insertion from the tree root
void insertAB(node ** root, node * child)
{
	if(!*root) *root = child;  // tree root not exists

    else if(child->value <= (*root)->value)
        insertAB(&(*root)->l, child); 	  // child value is minor/equal to current node call insertion on left node

    else
        insertAB(&(*root)->r, child); 	  // call insertion on right node

}

// recursive search of a node
node * searchAB(node * root, int value)
{
	if(root == NULL)
        return NULL;  		         // node not found
    else if (root->value == value)
        return root; 		         // first node address found

    else if(value > root->value)
        searchAB(root->r,value);	     // resursive search on right side of tree
    else
        searchAB(root->l,value);
}

void iguaisAB(DLList *a, node *b){
    DLNode *aux;
    num_comp+=2;
    if(a != NULL && b != NULL){
        aux = a->first;
        while(aux != NULL){
            num_comp++;
            if(searchAB(b,(int)aux->data) != NULL){
                printf("%d ",aux->data);
            }
            num_comp++;
            aux = aux->next;
        }
        num_comp++;
    }
}

void inserirBAAB(DLList *a, node *b){
    DLNode *aux;
    num_comp+=2;
    if(a != NULL && b != NULL){
        aux = a->first;
        while(aux != NULL){
            num_comp++;
            if(searchAB(b,(int)aux->data) == NULL){
                insertAB(&b, newAB((int)aux->data));
            }
            num_comp++;
            aux = aux->next;
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
        while(aux != NULL){
            num_comp++;
            if(searchAB(b,(int)aux->data) == NULL){
                dllInsertFirst(blz, aux->data);
            }
            num_comp++;
            aux = aux->next;
        }
        num_comp++;
    }
    return blz;
}

