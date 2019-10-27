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
    int valor;
    arquivo = fopen(a, "r");

    while((fscanf(arquivo,"%d",&valor) != EOF)){
        inserirArvore(valor, arvore);
    }
    fclose(arquivo);
}

tipoNo* noAvo(tipoNo *n){
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

tipoNo* noIrmao(tipoNo *n){
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

tipoNo* noTio(tipoNo *n){
    if(n == NULL){
        return NULL;
    }

    return noIrmao(n->noPai);
}


tipoNo* rotacaoEsquerda(tipoNo* raiz, tipoNo* n){
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

void rotacaoEsquerdaRR(tipoNo **x){

    tipoNo *y;
    y = *x;
    *x = (*x)->noDireito;
    (*x)->noPai = y->noPai;
    y->noDireito = (*x)->noEsquerdo;
    if(y->noDireito)    y->noDireito->noPai = y;
    (*x)->noEsquerdo = y;
    y->noPai = *x;

}


tipoNo* rotacaoDireita(tipoNo* raiz, tipoNo* n){
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

void rotacaoDireitaRR(tipoNo **x){
    tipoNo *y;
    y = *x;
    *x = (*x)->noEsquerdo;
    (*x)->noPai = y->noPai;
    y->noEsquerdo = (*x)->noDireito;
    if(y->noEsquerdo)   y->noEsquerdo->noPai = y;
    (*x)->noDireito = y;
    y->noPai = *x;
}

int verificaCor(tipoNo* n){
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

    if(n == n->noPai->noEsquerdo && n->noPai == noAvo(n)->noEsquerdo){
        raiz = rotacaoDireita(raiz, noAvo(n));
    }

    else if(n == n->noPai->noDireito && n->noPai == noAvo(n)->noDireito){
        raiz = rotacaoEsquerda(raiz, noAvo(n));
    }

    return raiz;
}

tipoNo* balanceamentoCaso4(tipoNo* raiz, tipoNo* n){
    if(n == n->noPai->noDireito && n->noPai == noAvo(n)->noEsquerdo){
        raiz = rotacaoEsquerda(raiz, n->noPai);
        n = n->noEsquerdo;
    }

    else if(n == n->noPai->noEsquerdo && n->noPai == noAvo(n)->noDireito){
        raiz = rotacaoDireita(raiz, n->noPai);
        n = n->noDireito;
    }

    return balanceamentoCaso5(raiz, n);
}

tipoNo* balanceamentoCaso3(tipoNo* raiz, tipoNo* n){
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
    if(n->noPai->cor == NEG){
        return raiz;
    }

    else{
        return balanceamentoCaso3(raiz, n);
    }
}

tipoNo* balanceamentoCaso1(tipoNo* raiz, tipoNo* n){
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
    return aux;
}

tipoNo* inserirElemento(int numero, tipoNo *raiz){
    tipoNo* novo = noNovo(numero);

    if(raiz == NULL){
        novo->cor = NEG;
        return novo;
    }

    tipoNo* aux = raiz;

    while(1){
        if(novo->dado == aux->dado){
            free (novo);
            return raiz;
        }

        else if(novo->dado < aux->dado){
            if(aux->noEsquerdo == NULL){
                aux->noEsquerdo = novo;
                novo->noPai = aux;
                return balanceamentoCaso1(raiz, novo);
            }

            else{
                aux = aux->noEsquerdo;
            }
        }

        else {
            if (aux->noDireito == NULL){
                aux->noDireito = novo;
                novo->noPai = aux;
                return balanceamentoCaso1(raiz, novo);
            }

            else{
                aux = aux->noDireito;
            }
        }
    }
}

void inserirArvore(int numero, tipoArvore* arvore){
    arvore->topo = inserirElemento(numero, arvore->topo);
}

tipoNo* buscarElemento(int numero, tipoNo *raiz){
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
    num_comp++;
    return raiz;
}

tipoNo* buscarNaArvore(int numero, tipoArvore arvore){
    return buscarElemento(numero, arvore.topo);
}

tipoNo* maiorDosMenores(tipoNo *raiz){
    tipoNo *aux;

    aux = raiz->noEsquerdo;

    if(aux == NULL){
        return NULL;
    }
    else{
        while (aux->noDireito != NULL){
            aux = aux->noDireito;
        }

    return aux;
    }
}

tipoNo* menorDosMaiores(tipoNo *raiz){
    tipoNo *aux;

    aux = raiz->noDireito;

    if(aux == NULL){
        return NULL;
    }
    else{
        while(aux->noEsquerdo != NULL){
            aux = aux->noEsquerdo;
        }
    return aux;
    }
}

tipoNo* conserta(tipoNo** raiz, tipoNo* no){
    tipoNo* aux;
    while((no != *raiz) && (verificaCor(no) == NEG)){
        if(no == no->noPai->noEsquerdo){
            aux = no->noPai->noDireito;

            if(verificaCor(aux) == RUB){
                aux->cor = NEG;
                no->noPai->cor = RUB;
                rotacaoEsquerdaRR(&no->noPai);
                aux = no->noPai->noDireito;
                continue;
            }

            if(verificaCor(aux->noEsquerdo) == NEG && verificaCor(aux->noDireito) == NEG){
                aux->cor = RUB;
                no = no->noPai;
                continue;
            }

            else if(verificaCor(aux->noDireito) == RUB){
                aux->noEsquerdo->cor = NEG;
                aux->cor = RUB;
                rotacaoDireitaRR(&aux);
                aux = aux->noPai->noDireito;
                continue;
            }
            aux->cor = no->noPai->cor;
            no->noPai->cor = NEG;
            aux->noDireito->cor = NEG;
            rotacaoEsquerdaRR(&no->noPai);
            no = *raiz;
        }

        else{
            aux = no->noPai->noEsquerdo;

            if(verificaCor(aux) == RUB){
                aux->cor = NEG;
                no->noPai->cor = RUB;
                rotacaoDireitaRR(&no->noPai);
                aux = no->noPai->noEsquerdo;
                continue;
            }

            if(verificaCor(aux->noEsquerdo) == NEG && verificaCor(aux->noDireito) == NEG){
                aux->cor = RUB;
                no = no->noPai;
                continue;
            }

            else if(verificaCor(aux->noEsquerdo) == RUB){
                aux->noDireito->cor = NEG;
                aux->cor = RUB;
                rotacaoEsquerdaRR(&aux);
                aux = aux->noPai->noEsquerdo;
                continue;
            }
            aux->cor = no->noPai->cor;
            no->noPai->cor = NEG;
            aux->noEsquerdo->cor = NEG;
            rotacaoDireitaRR(&no->noPai);
            no = *raiz;
        }
    }

    if(no != NULL){
        no->cor = NEG;
    }
    return *raiz;
}

tipoNo* transplante(tipoNo **raiz, tipoNo* no,tipoNo* noAux){
    if(no->noPai == NULL){
        *raiz = noAux;
    }

    else if(no == no->noPai->noEsquerdo){
        no->noPai->noEsquerdo = noAux;
    }

    else{
        no->noPai->noDireito = noAux;
    }

    if(noAux == NULL){
        return *raiz;
    }
    else{
        noAux->noPai = no->noPai;
        return *raiz;
    }
}

tipoNo* removerElemento(int numero, tipoNo *raiz){
    tipoNo *no;
    tipoNo *aux;
    tipoNo *M;

    int auxCor;

    no = buscarElemento(numero, raiz);

    if(raiz == NULL || no == NULL){
        return raiz;
    }

    auxCor = no->cor;

    if(no->noEsquerdo == NULL){
        aux = no->noDireito;
        transplante(&raiz,no, no->noDireito);
    }

    else if(no->noDireito == NULL){
        aux = no->noEsquerdo;
        transplante(&raiz, no, no->noEsquerdo);
    }

    else{
        M = menorDosMaiores(no);
        auxCor = M->cor;
        aux = M->noDireito;

        if(M->noPai == no){
            if(aux != NULL){
                aux->noPai = M;
            }
        }

        else{
            transplante(&raiz, M, M->noDireito);
            M->noDireito = no->noDireito;
            M->noDireito->noPai = M;
        }

        transplante(&raiz, no, M);
        M->noEsquerdo = no->noEsquerdo;
        M->noEsquerdo->noPai = M;
        M->cor = no->cor;
    }

    if(auxCor == NEG){
        if(aux!= NULL){
            conserta(&raiz, aux);
        }
    }

    free(no);

    return raiz;
}

void removerDaArvore(int numero, tipoArvore *arvore){
    arvore->topo = removerElemento(numero, arvore->topo);
}

int maior(int numeroA, int numeroB){
    if(numeroA > numeroB){
        return numeroA;
    }
    else {
        return numeroB;
    }
}

int calculaAltura(tipoNo *raiz){
    if(raiz == NULL){
        return 0;
    }
    else {
        return (maior(calculaAltura(raiz->noEsquerdo),calculaAltura(raiz->noDireito)) + 1);
    }
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
    if(a != NULL && b != NULL){
        aux = a->first;
        while(aux != NULL){
            if(buscarElemento((int)aux->data,b) != NULL){
                printf("%d ",aux->data);
            }
            num_comp++;
            aux = aux->next;
        }
    }
}

void inserirBARB(DLList *a, tipoNo *b)
{
    DLNode *aux;
    if(a != NULL && b != NULL){
        aux = a->first;
        while(aux != NULL){
            if(buscarElemento((int)aux->data,b) == NULL){
                inserirArvore((int)aux->data, &b);
            }
            num_comp++;
            aux = aux->next;
        }
    }
}

DLList *removerBARB(DLList *a, tipoNo *b)
{
    DLNode *aux;
    DLList *blz = dllCreate(NULL);
    if(a != NULL && b != NULL){
        aux = a->first;
        while(aux != NULL){
            if(buscarElemento(aux->data,b) == NULL){
                dllInsertFirst(blz, aux->data);
            }
            num_comp++;
            aux = aux->next;
        }
    }
    return blz;
}

