#include "geral.h"
#include "rbtree.h"
#define _RBTREE_C_

struct tipoNo{
    int dado;
    char cor;
    tipoNo *noPai;
    tipoNo *noEsquerdo;
    tipoNo *noDireito;
};

struct tipoArvore{
    tipoNo *topo;
};

// criarArvoreRB(&arvore);
// tipoArvore arvore;
// aux = buscarNaArvore(elemento, arvore);
// imprimirArvore(arvore.topo);
// removerDaArvore(elemento, &arvore);

void criarArvoreRB(tipoArvore *arvore,char a[]){
    arvore->topo = NULL;
    FILE *arquivo;
    int dado;
    arquivo = fopen(a, "r");

    while((fscanf(arquivo,"%d",&dado) != EOF)){
        inserirArvoreCriacao(dado, arvore);
    }
    fclose(arquivo);
}

tipoNo* balanceamentoCaso1Criacao(tipoNo* raiz, tipoNo* n){
    if(n->noPai == NULL){
        n->cor = NEG;
        return raiz;
    }

    else{
        return balanceamentoCaso2Criacao(raiz, n);
    }
}

tipoNo* balanceamentoCaso2Criacao(tipoNo* raiz, tipoNo* n){
    if(n->noPai->cor == NEG){
        return raiz;
    }

    else{
        return balanceamentoCaso3Criacao(raiz, n);
    }
}

tipoNo* balanceamentoCaso3Criacao(tipoNo* raiz, tipoNo* n){
    if(verificaCorCriacao(noTioCriacao(n)) == RUB){
        n->noPai->cor = NEG;
        noTio(n)->cor = NEG;
        noAvo(n)->cor = RUB;
        return balanceamentoCaso1Criacao(raiz, noAvoCriacao(n));
    }

    else{
        return balanceamentoCaso4Criacao(raiz, n);
    }
}

int verificaCorCriacao(tipoNo* n){
    if(n == NULL){
        return NEG;
    }
    else{
        return n->cor;
    }
}

tipoNo* balanceamentoCaso4Criacao(tipoNo* raiz, tipoNo* n){
    if(n == n->noPai->noDireito && n->noPai == noAvoCriacao(n)->noEsquerdo){
        raiz = rotacaoEsquerdaCriacao(raiz, n->noPai);
        n = n->noEsquerdo;
    }

    else if(n == n->noPai->noEsquerdo && n->noPai == noAvoCriacao(n)->noDireito){
        raiz = rotacaoDireitaCriacao(raiz, n->noPai);
        n = n->noDireito;
    }

    return balanceamentoCaso5Criacao(raiz, n);
}

tipoNo* rotacaoDireitaCriacao(tipoNo* raiz, tipoNo* n){
    tipoNo* l = n->noEsquerdo;

    if(n == NULL){
        return raiz;
    }

    if(raiz == n){
        raiz = l;
    }

    else if(n == n->noPai->noEsquerdo){
        n->noPai->noEsquerdo = l;
    }

    else{
        n->noPai->noDireito = l;
    }

    n->noEsquerdo = l->noDireito;

    if(l->noDireito != NULL){
        l->noDireito->noPai = n;
    }

    l->noDireito = n;
    l->noPai = n->noPai;
    n->noPai = l;

    return raiz;
}

tipoNo* rotacaoEsquerdaCriacao(tipoNo* raiz, tipoNo* n){
    tipoNo* r = n->noDireito;

    if(n == NULL){
        return raiz;
    }

    if(raiz == n){
        raiz = r;
    }

    else if(n == n->noPai->noEsquerdo){
        n->noPai->noEsquerdo = r;
    }

    else{
        n->noPai->noDireito = r;
    }

    n->noDireito = r->noEsquerdo;

    if(r->noEsquerdo != NULL){
        r->noEsquerdo->noPai = n;
    }

    r->noEsquerdo = n;
    r->noPai = n->noPai;
    n->noPai = r;

    return raiz;
}

tipoNo* balanceamentoCaso5Criacao(tipoNo* raiz, tipoNo* n){
    n->noPai->cor = NEG;
    noAvoCriacao(n)->cor = RUB;

    if(n == n->noPai->noEsquerdo && n->noPai == noAvoCriacao(n)->noEsquerdo){
        raiz = rotacaoDireitaCriacao(raiz, noAvoCriacao(n));
    }

    else if(n == n->noPai->noDireito && n->noPai == noAvoCriacao(n)->noDireito){
        raiz = rotacaoEsquerdaCriacao(raiz, noAvoCriacao(n));
    }

    return raiz;
}

tipoNo* noAvoCriacao(tipoNo *n){
    if(n == NULL){
        return NULL;
    }

    if(n->noPai == NULL){
        return NULL;
    }

    else{
        return n->noPai->noPai;
    }
}

tipoNo* noIrmaoCriacao(tipoNo *n){
    if(n == NULL){
        return NULL;
    }

    if(n->noPai == NULL){
        return NULL;
    }

    if(n == n->noPai->noEsquerdo){
        return n->noPai->noDireito;
    }

    else{
        return n->noPai->noEsquerdo;
    }
}

tipoNo* noTioCriacao(tipoNo *n){
    if(n == NULL){
        return NULL;
    }

    return noIrmaoCriacao(n->noPai);
}

tipoNo* noAvo(tipoNo *n){
    num_comp++;
    if(n == NULL){
        return NULL;
    }
    num_comp++;
    if(n->noPai == NULL){
        return NULL;
    }

    else{
        return n->noPai->noPai;
    }
}

tipoNo* noIrmao(tipoNo *n){
    num_comp++;
    if(n == NULL){
        return NULL;
    }
    num_comp++;
    if(n->noPai == NULL){
        return NULL;
    }
    num_comp++;
    if(n == n->noPai->noEsquerdo){
        return n->noPai->noDireito;
    }

    else{
        return n->noPai->noEsquerdo;
    }
}

tipoNo* noTio(tipoNo *n){
    num_comp++;
    if(n == NULL){
        return NULL;
    }

    return noIrmao(n->noPai);
}


tipoNo* rotacaoEsquerda(tipoNo* raiz, tipoNo* n){
    num_atb++;
    tipoNo* r = n->noDireito;
    num_comp++;
    if(n == NULL){
        return raiz;
    }
    num_comp++;
    if(raiz == n){
        num_atb++;
        raiz = r;
    }

    else if(++num_comp && n == n->noPai->noEsquerdo){
        num_atb++;
        n->noPai->noEsquerdo = r;
    }

    else{
        num_atb++;
        n->noPai->noDireito = r;
    }
    num_atb++;
    n->noDireito = r->noEsquerdo;
    num_comp++;
    if(r->noEsquerdo != NULL){
        num_atb++;
        r->noEsquerdo->noPai = n;
    }

    r->noEsquerdo = n;
    r->noPai = n->noPai;
    n->noPai = r;
    num_atb+=3;
    return raiz;
}

tipoNo* rotacaoDireita(tipoNo* raiz, tipoNo* n){
    num_atb++;
    tipoNo* l = n->noEsquerdo;
    num_comp++;
    if(n == NULL){
        return raiz;
    }
    num_comp++;
    if(raiz == n){
        num_atb++;
        raiz = l;
    }

    else if(++num_comp && n == n->noPai->noEsquerdo){
        num_atb++;
        n->noPai->noEsquerdo = l;
    }

    else{
        num_atb++;
        n->noPai->noDireito = l;
    }
    num_atb++;
    n->noEsquerdo = l->noDireito;

    if(l->noDireito != NULL){
        num_atb++;
        l->noDireito->noPai = n;
    }

    l->noDireito = n;
    l->noPai = n->noPai;
    n->noPai = l;
    num_atb+=3;
    return raiz;
}

int verificaCor(tipoNo* n){
    num_comp++;
    if(n == NULL){
        return NEG;
    }

    else{
        return n->cor;
    }
}

tipoNo* balanceamentoCaso5(tipoNo* raiz, tipoNo* n){
    n->noPai->cor = NEG;
    noAvo(n)->cor = RUB;
    num_comp+=2;
    if(n == n->noPai->noEsquerdo && n->noPai == noAvo(n)->noEsquerdo){
        raiz = rotacaoDireita(raiz, noAvo(n));
    }

    else if(num_comp+= 2 && n == n->noPai->noDireito && n->noPai == noAvo(n)->noDireito){
        raiz = rotacaoEsquerda(raiz, noAvo(n));
    }

    return raiz;
}

tipoNo* balanceamentoCaso4(tipoNo* raiz, tipoNo* n){
    num_comp+=2;
    if(n == n->noPai->noDireito && n->noPai == noAvo(n)->noEsquerdo){
        raiz = rotacaoEsquerda(raiz, n->noPai);
        n = n->noEsquerdo;
    }

    else if(num_comp+= 2 && n == n->noPai->noEsquerdo && n->noPai == noAvo(n)->noDireito){
        raiz = rotacaoDireita(raiz, n->noPai);
        n = n->noDireito;
    }

    return balanceamentoCaso5(raiz, n);
}

tipoNo* balanceamentoCaso3(tipoNo* raiz, tipoNo* n){
    num_comp++;
    if(verificaCor(noTio(n)) == RUB){
        n->noPai->cor = NEG;
        noTio(n)->cor = NEG;
        noAvo(n)->cor = RUB;
        return balanceamentoCaso1(raiz, noAvo(n));
    }

    else{
        return balanceamentoCaso4(raiz, n);
    }
}

tipoNo* balanceamentoCaso2(tipoNo* raiz, tipoNo* n){
    num_comp++;
    if(n->noPai->cor == NEG){
        return raiz;
    }

    else{
        return balanceamentoCaso3(raiz, n);
    }
}

tipoNo* balanceamentoCaso1(tipoNo* raiz, tipoNo* n){
    num_comp++;
    if(n->noPai == NULL){
        n->cor = NEG;
        return raiz;
    }

    else{
        return balanceamentoCaso2(raiz, n);
    }
}

tipoNo* noNovo(int dado){
    tipoNo* aux;

    aux = (tipoNo *) malloc (sizeof(tipoNo));
    aux->dado = dado;
    aux->cor = RUB;
    aux->noEsquerdo = NULL;
    aux->noDireito = NULL;
    aux->noPai = NULL;
    num_atb+=6;
    return aux;
}

tipoNo* noNovoCriacao(int dado){
    tipoNo* aux;

    aux = (tipoNo *) malloc (sizeof(tipoNo));
    aux->dado = dado;
    aux->cor = RUB;
    aux->noEsquerdo = NULL;
    aux->noDireito = NULL;
    aux->noPai = NULL;
    return aux;
}

tipoNo* inserirElementoCriacao(int numero, tipoNo *raiz){
    tipoNo* novo = noNovoCriacao(numero);
    if(raiz == NULL){
        novo->cor = NEG;
        return novo;
    }

    tipoNo* aux = raiz;

    while(1){
        if(novo->dado == aux->dado){
            free (novo);
            return raiz;
        }else if(novo->dado < aux->dado){
            if(aux->noEsquerdo == NULL){
                aux->noEsquerdo = novo;
                novo->noPai = aux;
                return balanceamentoCaso1Criacao(raiz, novo);
            }

            else{
                aux = aux->noEsquerdo;
            }
        }

        else {
            if (aux->noDireito == NULL){
                aux->noDireito = novo;
                novo->noPai = aux;
                return balanceamentoCaso1Criacao(raiz, novo);
            }

            else{
                aux = aux->noDireito;
            }
        }
    }
}

tipoNo* inserirElemento(int numero, tipoNo *raiz){
    num_atb++;
    tipoNo* novo = noNovo(numero);
    num_comp++;
    if(raiz == NULL){
        num_atb+=2;
        novo->cor = NEG;
        return novo;
    }
    num_atb++;
    tipoNo* aux = raiz;

    while(1){
        num_comp+=2;
        if(novo->dado == aux->dado){
            free (novo);
            return raiz;
        }else if(++num_comp && novo->dado < aux->dado){
            num_comp++;
            if(aux->noEsquerdo == NULL){
                num_atb+=2;
                aux->noEsquerdo = novo;
                novo->noPai = aux;
                return balanceamentoCaso1(raiz, novo);
            }

            else{
                num_atb++;
                aux = aux->noEsquerdo;
            }
        }

        else {
            num_comp++;
            if (aux->noDireito == NULL){
                num_atb+=2;
                aux->noDireito = novo;
                novo->noPai = aux;
                return balanceamentoCaso1(raiz, novo);
            }

            else{
                num_atb++;
                aux = aux->noDireito;
            }
        }
    }
    num_comp++;
}

void inserirArvore(int numero, tipoArvore* arvore){
    num_atb++;
    arvore->topo = inserirElemento(numero, arvore->topo);
}

void inserirArvoreCriacao(int numero, tipoArvore* arvore){
    arvore->topo = inserirElementoCriacao(numero, arvore->topo);
}

tipoNo* buscarElemento(int numero, tipoNo *raiz){
    num_comp++;
    if(raiz == NULL){
        return NULL;
    }
    num_comp++;
    if (numero < raiz->dado){
        return buscarElemento(numero, raiz->noEsquerdo);
    }
    num_comp++;
    if(numero > raiz->dado){
        return buscarElemento(numero,raiz->noDireito);
    }
    return raiz;
}

tipoNo* buscarNaArvore(int numero, tipoArvore arvore){
    return buscarElemento(numero, arvore.topo);
}

 void preOrderRB(tipoNo *root)
{
	if(root != NULL)
	{
		printf("%d", root->dado);
		if(root->cor == RUB){
            printf("(V) ");
		}else{
            printf("(P) ");
		}
		preOrderRB(root->noEsquerdo);
		preOrderRB(root->noDireito);
	}
}

void igualRB(DLList *a, tipoNo *b)
{
    DLNode *aux;
    num_comp+=2;
    if(a != NULL && b != NULL){
        aux = a->first;
        num_atb++;
        while(aux != NULL){
            num_comp++;
            if(buscarElemento((int)aux->data,b) != NULL){
                printf("%d ",aux->data);
            }
            num_comp++;
            aux = aux->next;
            num_atb++;
        }
        num_comp++;
    }
}

void inserirBARB(DLList *a, tipoNo *b)
{
    DLNode *aux;
    num_comp+=2;
    if(a != NULL && b != NULL){
        aux = a->first;
        num_atb++;
        while(aux != NULL){
            num_comp++;
            if(buscarElemento((int)aux->data,b) == NULL){
                inserirArvore((int)aux->data, &b);
            }
            num_comp++;
            aux = aux->next;
            num_atb++;
        }
        num_comp++;
    }
}

DLList *removerBARB(DLList *a, tipoNo *b)
{
    DLNode *aux;
    DLList *blz = dllCreate(NULL);
    num_comp+=2;
    if(a != NULL && b != NULL){
        aux = a->first;
        num_atb++;
        while(aux != NULL){
            num_comp++;
            if(buscarElemento(aux->data,b) == NULL){
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

