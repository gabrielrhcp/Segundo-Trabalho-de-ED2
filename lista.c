#define _LIST_C_
#include "geral.h"
#include "lista.h"

struct _dllelm_{
    DLNode *next, *prev;
    void* data;
};

struct _dllist_{
    DLNode* first;
    DLNode* cur;
};

int dllCmp(void *a, void *b){
	int ac = (int)a;
	int bc = (int)b;
	if(ac == bc){
		return TRUE;
	}
	return FALSE;
}

DLList* dllCreate(int i){
	DLList* list = malloc(sizeof(DLList));
	if(list != NULL){
		list->first = NULL;
		list->cur = NULL;
	}
	FILE *arquivo;
    int valor;
    if(i == 1){
        arquivo = fopen("dados/dadosA.txt", "r");
    }else{
        arquivo = fopen("dados/dadosB.txt", "r");
    }
    while(fscanf(arquivo,"%d",&valor) != EOF){
        dllInsertFirst(list, (void*)valor);
    }
    fclose(arquivo);
    return list;
}

int dllDestroy(DLList* list){
	if(list != NULL){
		if(list->first == NULL){
			free(list);
			return TRUE;
		}
	}
	return FALSE;
}

int dllInsertFirst(DLList *list, void *data){
	DLNode* newNode;
	if(list != NULL){
		newNode = (DLNode*)malloc(sizeof(DLNode));
		if(newNode != TRUE){
			newNode->data = data;
			newNode->prev = NULL;
			if(list -> first != NULL){
				list->first->prev = newNode;
				newNode -> next = list->first;
			}else{
				newNode->next = NULL;
			}
			list->first = newNode;
			return TRUE;
		}
	}
	return FALSE;
}

DLNode* dllGetNode(DLList* l, void *key, int(*cmp)(void*,void*)){
	DLNode *spec;
	int stat;
	if(l!=NULL){
		if(l->first != NULL){
			spec = l->first;
			stat = cmp(key, spec->data);
			while(stat != TRUE && spec->next != NULL){
				spec = spec->next;
				stat = cmp(key, spec->data);
			}
			if(stat){
				return spec;
			}
		}
	}
	return NULL;
}

void* dllQuery(DLList *list, void* key, int(*cmp)(void*,void*)){
	DLNode *spec;
	void *data;
	if(list != NULL){
		if(list->first != NULL){
			spec = dllGetNode(list, key, cmp);
			if(spec != NULL){
				data = spec->data;
				return data;
			}
		}
	}
	return NULL;
}

void* dllRemoveSpec(DLList *list, void* key, int(*cmp)(void*,void*)){
	DLNode *spec, *prev, *next;
	void* data;
	if(list != NULL){
		if(list->first != NULL){
			spec = dllGetNode(list, key, cmp);
			if(spec != NULL){
				data = spec->data;
				prev = spec->prev;
				next = spec->next;
				if(prev != NULL){
					prev->next = spec -> next;
				}else{
					list->first = spec->next;
				}
				if( next!= NULL){
					next->prev = prev;
				}
				free(spec);
				return data;
			}
		}
	}
	return NULL;
}

void printLista(DLList *list){
    DLNode *aux;
    if(list != NULL){
        aux = list->first;
        while(aux != NULL){
            printf("%d ",(int)aux->data);
            aux = aux->next;
        }
    }
}

void DLLprintIguais(DLList *a, DLList *b, int (*cmp)(void*,void*)){
    DLNode *aux;
    if(a != NULL && b != NULL){
        aux = a->first;
        while(aux != NULL){
            if(dllQuery(b,aux->data,cmp) != NULL){
                printf("%d ",(int)aux->data);
            }
            aux = aux->next;
        }
    }
}

void DLLinserirListaBA(DLList *a, DLList *b, int(*cmp)(void*,void*)){
    DLNode *aux;
    if(a != NULL && b != NULL){
        aux = a->first;
        while(aux != NULL){
            if(dllQuery(b,aux->data,cmp) == NULL){
               dllInsertFirst(b,aux->data);
            }
            aux = aux->next;
        }
    }
}

void DLLremoverListaAB(DLList *a, DLList *b, int(*cmp)(void*,void*)){
    DLNode *aux;
    if(a != NULL && b != NULL){
        aux = a->first;
        while(aux != NULL){
            if(dllQuery(b,aux->data,cmp) != NULL){
               dllRemoveSpec(b,aux->data,cmp);
            }
            aux = aux->next;
        }
    }
}
