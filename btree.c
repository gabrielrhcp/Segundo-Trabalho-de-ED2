#include "geral.h"
#include "btree.h"
#define _BTREE_C_

struct t_elemento{
	int num;
};

struct s_no{
	t_no *esq;
	t_elemento dado;
	t_no *dir;
};

t_no *criaNoBT(int i)
{
	t_no *novo = NULL;

	novo = (t_no *) malloc (sizeof(t_no));
	if(novo != NULL)
	{
		novo->esq = novo->dir = novo->dado.num = NULL;
	}

    FILE *arquivo;
    t_elemento valor;
    if(i == 1){
        arquivo = fopen("dados/dadosA.txt", "r");
    }else if(i == 2){
        arquivo = fopen("dados/dadosB.txt", "r");
    }

    if(i == 1 || i == 2){
        while((fscanf(arquivo,"%d",&valor.num) != EOF)){
            inserir(novo, valor);
        }
        fclose(arquivo);
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

int comparaBT(t_elemento item1, t_elemento item2)
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
		if(comparaBT(raiz->dado, dado) == 0)
			no = raiz;
		else
		{
			no = busca(raiz->esq, dado);

			if(no == NULL){
                no = busca(raiz->dir, dado);
			}
            num_comp++;
		}
		num_comp++;
	}
	num_comp++;

	return no;
}

t_no *buscaSetPai (t_arvore raiz, t_elemento dado, t_no **pai)
{
	t_no *no = NULL;

	if(raiz == NULL)
		*pai = NULL;
	else
	{
		if(comparaBT(raiz->dado, dado) == 0)
			no = raiz;
		else
		{
			*pai = raiz;

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
		if(comparaBT((*raiz)->dado, item) > 0)
			result = inserir(&((*raiz)->esq), item);
		else if(comparaBT((*raiz)->dado, item) < 0)
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

void iguaisBT(t_arvore a, t_arvore b)
{
	if(a != NULL)
	{
		if(busca(b, a->dado) != NULL){
            printf("%d ",a->dado.num);
		}
		num_comp++;
		iguaisBT(a->esq, b);
		iguaisBT(a->dir, b);
	}
}

t_no *inserirBABT(t_arvore a, t_arvore b)
{
	if(a != NULL)
	{
		if(busca(b, a->dado) == NULL){
            inserir(b, a->dado);
		}
		num_comp++;
		b = inserirBABT(a->esq, b);
		b = inserirBABT(a->dir, b);
	}

	return b;
}

t_no *removerABBT(t_arvore a, t_arvore b)
{
	if(a != NULL)
	{
		if(busca(b, a->dado) != NULL){
            remover(b, a->dado);
		}
		num_comp++;
		b = removerABBT(a->esq, b);
		b = removerABBT(a->dir, b);
	}

	return b;
}
