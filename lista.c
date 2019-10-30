#define _LIST_C_
#include "geral.h"
#include "lista.h"

int dllCmp(void *a, void *b){
	int ac = (int)a;
	int bc = (int)b;
	num_comp++;
	if(ac == bc){
		return TRUE;
	}
	return FALSE;
}

DLList* dllCreate(char a[]){
	DLList* list = malloc(sizeof(DLList));
	if(list != NULL){
		list->first = NULL;
		list->cur = NULL;
	}

	FILE *arquivo;
    int valor;

    if(a != NULL){
        arquivo = fopen(a, "r");
        while(fscanf(arquivo,"%d",&valor) != EOF){
            dllInsertFirstCriacao(list, (void*)valor);
        }
        fclose(arquivo);
	}

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
	num_comp++;
	if(list != NULL){
		newNode = (DLNode*)malloc(sizeof(DLNode));
		num_comp++;
		if(newNode != TRUE){
			newNode->data = data;
			newNode->prev = NULL;
			num_comp++;
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

int dllInsertFirstCriacao(DLList *list, void *data){
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
	num_comp++;
	if(l!=NULL){
        num_comp++;
		if(l->first != NULL){
			spec = l->first;
			stat = cmp(key, spec->data);
			while(stat != TRUE && spec->next != NULL){
			    num_comp+=2;
				spec = spec->next;
				stat = cmp(key, spec->data);
			}
			num_comp+=3;
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
	num_comp++;
	if(list != NULL){
        num_comp++;
		if(list->first != NULL){
			spec = dllGetNode(list, key, cmp);
            num_comp++;
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
	num_comp++;
	if(list != NULL){
        num_comp++;
		if(list->first != NULL){
			spec = dllGetNode(list, key, cmp);
            num_comp++;
			if(spec != NULL){
				data = spec->data;
				prev = spec->prev;
				next = spec->next;
				num_comp++;
				if(prev != NULL){
					prev->next = spec -> next;
				}else{
					list->first = spec->next;
				}
				num_comp++;
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
    num_comp+=2;
    if(a != NULL && b != NULL){
        aux = a->first;
        while(aux != NULL){
            num_comp++;
            if(dllQuery(b,aux->data,cmp) != NULL){
                printf("%d ",(int)aux->data);
            }
            num_comp++;
            aux = aux->next;
        }
        num_comp++;
    }
}

void DLLinserirListaBA(DLList *a, DLList *b, int(*cmp)(void*,void*)){
    DLNode *aux;
    num_comp+=2;
    if(a != NULL && b != NULL){
        aux = a->first;
        while(aux != NULL){
            num_comp++;
            if(dllQuery(b,aux->data,cmp) == NULL){
               dllInsertFirst(b,aux->data);
            }
            num_comp++;
            aux = aux->next;
        }
        num_comp++;
    }
}

void DLLremoverListaAB(DLList *a, DLList *b, int(*cmp)(void*,void*)){
    DLNode *aux;
    num_comp+=2;
    if(a != NULL && b != NULL){
        aux = a->first;
        while(aux != NULL){
            num_comp++;
            if(dllQuery(b,aux->data,cmp) != NULL){
               dllRemoveSpec(b,aux->data,cmp);
            }
            num_comp++;
            aux = aux->next;
        }
        num_comp++;
    }
}

