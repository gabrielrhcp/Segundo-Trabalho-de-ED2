#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "btree.h"
#define _BTREE_C_

struct t_ele{
	int num;
};

struct s_no{
	t_no *esq;
	t_elemento dado;
	t_no *dir;
};

t_no *criaNo (void)
{
	t_no *novo = NULL;

	novo = (t_no *) malloc (sizeof(t_no));
	if(novo != NULL)
	{
		novo->esq = novo->dir = NULL;
		novo->dado.num = 0;
	}

	return novo;
}

bool isVazia (t_no *no)
{
	bool result = true;

	if(no == NULL)
		result = false;

	return result;
}

int comparaB(t_elemento item1, t_elemento item2)
{
	int result = 0;

	if(item1.num > item2.num)
		result = 1;
	else if(item1.num < item2.num)
		result = -1;

	return result;
}

t_no *busca (t_arvore raiz, t_elemento dado)
{
	t_no *no = NULL;

	if(raiz != NULL)
	{
		if(comparaB(raiz->dado, dado) == 0)
			no = raiz;
		else
		{
			no = busca(raiz->esq, dado);

			if(no == NULL)
				no = busca(raiz->dir, dado);
		}
	}

	return no;
}

t_no *buscaSetPai (t_arvore raiz, t_elemento dado, t_no **pai)
{
	t_no *no = NULL;

	if(raiz == NULL)
		*pai = NULL;
	else
	{
		if(comparaB(raiz->dado, dado) == 0)
			no = raiz;
		else
		{
			*pai = raiz;

			if(comparaB(raiz->dado, dado) > 0)
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

	if(*raiz == NULL)
	{
		*raiz = criaNo();

		if(*raiz != NULL)
		{
			(*raiz)->dado = item;
			result = true;
		}
	}
	else
	{
		if(comparaB((*raiz)->dado, item) > 0)
			result = inserir(&((*raiz)->esq), item);
		else if(comparaB((*raiz)->dado, item) < 0)
			result = inserir(&((*raiz)->dir), item);
	}

	return result;
}

bool remover (t_arvore *raiz, t_elemento item)
{
	bool result = false;
	t_no *no, *pai, *sub, *paiSuc, *suc;

	no = pai = sub = paiSuc = suc = NULL;

	no = buscaSetPai(*raiz, item, &pai);
	if(no != NULL)
	{
		if(no->esq == NULL)
			sub = no->dir;
		else
		{
			if(no->dir == NULL)
				sub = no->esq;
			else
			{
				paiSuc = no;
				sub = no->dir;
				suc = sub->esq;

				while(suc != NULL)
				{
					paiSuc = sub;
					sub = suc;
					suc = sub->esq;
				}

				if(paiSuc != no)
				{
					paiSuc->esq = sub->dir;
					sub->dir = no->dir;
				}

				sub->esq = no->esq;
			}
		}

		if(pai == NULL)
			*raiz = sub;
		else
		{
			if(no == pai->esq)
				pai->esq = sub;
			else
				pai->dir = sub;

			free(no);
			result = true;
		}

	}

	return result;
}

void esvaziar (t_arvore *raiz)
{
	if(*raiz != NULL)
	{
		esvaziar(&(*raiz)->esq);
		esvaziar(&(*raiz)->dir);
		free(*raiz);
		*raiz = NULL;
	}
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
