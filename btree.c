#include "geral.h"
#include "btree.h"
#define _BTREE_C_

t_no *criaNoBT(char a[])
{
	t_no *novo = NULL;

	novo = (t_no *) malloc (sizeof(t_no));
	if(novo != NULL)
	{
		novo->esq = novo->dir = novo->dado.num = NULL;
	}

    FILE *arquivo;
    t_elemento valor;
    arquivo = fopen(a, "r");
    while((fscanf(arquivo,"%d",&valor.num) != EOF)){
        inserirNaCriacao(novo, valor);
    }
    fclose(arquivo);

	return novo;
}

bool isVazia (t_no *no)
{
	bool result = true;

	if(no == NULL)
		result = false;

	return result;
}

int comparaBT(t_elemento item1, t_elemento item2)
{
	int result = 0;
    num_comp++;
	if(item1.num > item2.num){
        return 1;
	}else if(++num_comp && item1.num < item2.num){
        result = -1;
	}


	return result;
}

int comparaBTCriacao(t_elemento item1, t_elemento item2)
{
	int result = 0;
	if(item1.num > item2.num){
        return 1;
	}else if(item1.num < item2.num){
        result = -1;
	}

	return result;
}

t_no *busca (t_arvore raiz, t_elemento dado)
{
	t_no *no = NULL;
    num_comp++;
	if(raiz != NULL)
	{
	    num_comp++;
		if(comparaBT(raiz->dado, dado) == 0)
			no = raiz;
		else
		{
			no = busca(raiz->esq, dado);
            num_comp++;
			if(no == NULL){
                no = busca(raiz->dir, dado);
			}
		}
	}

	return no;
}

t_no *buscaSetPai (t_arvore raiz, t_elemento dado, t_no **pai)
{
	t_no *no = NULL;
    num_comp++;
	if(raiz == NULL)
		*pai = NULL;
	else
	{   num_comp++;
		if(comparaBT(raiz->dado, dado) == 0)
			no = raiz;
		else
		{
			*pai = raiz;
            num_comp++;
			if(comparaBT(raiz->dado, dado) > 0)
				no = buscaSetPai(raiz->esq, dado, pai);
			else
				no = buscaSetPai(raiz->dir, dado, pai);
		}
	}

	return no;
}

bool inserir (t_arvore *raiz, t_elemento item)
{
	bool result = false;
    num_comp++;
	if(*raiz == NULL)
	{
		*raiz = criaNoBT(0);
        num_comp++;
		if(*raiz != NULL)
		{
			(*raiz)->dado = item;
			result = true;
		}
	}
	else
	{   num_comp++;
		if(comparaBT((*raiz)->dado, item) > 0){
            result = inserir(&((*raiz)->esq), item);
		}else if(++num_comp && comparaBT((*raiz)->dado, item) < 0){
            result = inserir(&((*raiz)->dir), item);
		}

	}

	return result;
}

bool inserirNaCriacao(t_arvore *raiz, t_elemento item)
{
	bool result = false;
	if(*raiz == NULL)
	{
		*raiz = criaNoBT(0);
		if(*raiz != NULL)
		{
			(*raiz)->dado = item;
			result = true;
		}
	}
	else
	{
		if(comparaBTCriacao((*raiz)->dado, item) > 0){
            result = inserirNaCriacao(&((*raiz)->esq), item);
		}else if(comparaBTCriacao((*raiz)->dado, item) < 0){
            result = inserirNaCriacao(&((*raiz)->dir), item);
		}

	}

	return result;
}

void exibirPreOrdem (t_arvore raiz)
{
	if(raiz != NULL)
	{
		printf("%d ", raiz->dado.num);
		exibirPreOrdem(raiz->esq);
		exibirPreOrdem(raiz->dir);
	}
}

void iguaisBT(DLList *a, t_arvore b)
{
	DLNode *aux;
	t_elemento aux2;
	num_comp+=2;
    if(a != NULL && b != NULL){
        aux = a->first;
        while(aux != NULL){
            num_comp++;
            aux2.num = (int)aux->data;
            if(busca(b,aux2) != NULL){
                printf("%d ",aux2.num);
            }
            num_comp++;
            aux = aux->next;
        }
        num_comp++;
    }
}

void inserirBABT(DLList *a, t_arvore *b)
{
	DLNode *aux;
	t_elemento aux2;
	num_comp+=2;
    if(a != NULL && b != NULL){
        aux = a->first;
        while(aux != NULL){
            num_comp++;
            aux2.num = (int)aux->data;
            if(busca(b,aux2) == NULL){
                inserir(*b, aux2);
            }
            num_comp++;
            aux = aux->next;
        }
        num_comp++;
    }
}

DLList *removerABBT(DLList *a, t_arvore *b)
{
	t_elemento aux2;
    DLNode *aux;
    DLList *blz = dllCreate(NULL);
    num_comp+=2;
    if(a != NULL && b != NULL){
        aux = a->first;
        while(aux != NULL){
            num_comp++;
            aux2.num = (int)aux->data;
            if(busca(b,aux2) == NULL){
                dllInsertFirst(blz, aux->data);
            }
            num_comp++;
            aux = aux->next;
        }
        num_comp++;
    }
    return blz;
}
