#include "hash.h"
#include "geral.h"
#define _HASH_C_

struct _hashOpen_{
	int currentSize;
	int maxSize;
	int * flags;
	int * keys;
	int * vals;
};

HashOpen * hlCreate(int size, char dados[]){
	HashOpen * hl = (HashOpen*)malloc(sizeof(HashOpen));
	if(hl != NULL){
		hl->currentSize = 0;
		hl->maxSize = size;
		hl->flags = calloc(size, sizeof(int));
		hl->keys = (int*)malloc(sizeof(int)*size);
		hl->vals = (int*)malloc(sizeof(int)*size);
		FILE *arq;
        arq = fopen(dados,"r");
        int aux;
        while(fscanf(arq,"%d",&aux) != EOF){
            hlInsertLinear(hl, hl->currentSize, (void*)aux);
        }
        fclose(arq);
		return hl;
	}
	return NULL;
}

int hlClear(HashOpen * hl){
	if(hl != NULL){
		hl->currentSize = 0;
		hl->keys = (int*)malloc(sizeof(int)*hl->maxSize);
		hl->vals = (int*)malloc(sizeof(int*)*hl->maxSize);
		return TRUE;
	}
	return FALSE;
}

int hlGetSize(HashOpen * hl){
	if(hl != NULL){
		return hl->currentSize;
	}
	return FALSE;
}

int hlIsFull(HashOpen * hl){
	if(hl != NULL){
		if(hl->currentSize == hl->maxSize){
			return TRUE;
		}
	}
	return FALSE;
}

int hlIsEmpty(HashOpen * hl){
	if(hl != NULL){
		if(hl->currentSize == 0){
			return TRUE;
		}
	}
	return FALSE;
}

int * hlGetValues(HashOpen * hl){
	return hl->vals;
}

int hlInsertLinear(HashOpen * hl, int key, int data){
	if(hl != NULL){
		int tmp = key % hl->maxSize;
		int i = tmp;
		do{
			if(hl->flags[i] == 0){
				hl->keys[i] = key;
				hl->vals[i] = data;
				hl->flags[i] = 1;
				hl->currentSize++;
				return TRUE;
			}
			if(hl->keys[i] == key){
				hl->vals[i] = data;
				return TRUE;
			}
			i = (i + 1) % hl->maxSize;
		} while(i != tmp);
	}
	return FALSE;
}

int hlGetLinear(HashOpen * hl, int key){
	if(hl != NULL){
		int i = key % hl->maxSize;
        int tmp = i;
		do{
            num_comp++;
			if(hl->flags[i] == 1){
                num_comp++;
				if(hl->vals[i] == key){
                    return hl->vals[i];
                }
			}
			i = (i + 1) % hl->maxSize;
            num_comp++;
		} while(i != tmp);
	}
	return -1;
}

int hlContainsLinear(HashOpen *hl, int key){
    num_comp++;
	if(hlGetLinear(hl, key) != -1){
		return TRUE;
	}
	return FALSE;
}

int hlRemoveLinear(HashOpen * hl, int key){
	if(hl != NULL){
		if(hlContainsLinear(hl, key) == FALSE){
			return FALSE;
		}
		int i = key % hl->maxSize;
		while(!(hl->keys[i] == key)){
			i = (i + 1) % hl->maxSize;
		}
		hl->flags[i] = 0;
		hl->vals[i] = 0;
		i = (i + 1) % hl->maxSize;
		while(hl->flags[i] == 1){
			int keyT = hl->keys[i];
			int dataT = hl->vals[i];
			hl->flags[i] = 0;
			hl->vals[i] = 0;
			hl->currentSize--;
			hlInsertLinear(hl, keyT, dataT);
		}
		hl->currentSize--;
		return TRUE;
	}
	return FALSE;
}

void hlPrint(HashOpen * hl){
	if(hl != NULL){
		for(int i = 0; i < hl->maxSize; i++){
			if(hl->flags[i] == 1){
				printf("%d|%d ", hl->keys[i], hl->vals[i]);
			}
		}
	}
}

void hlIguais(DLList *a, HashOpen *b){
    DLNode *aux;
    if(a != NULL && b != NULL){
        aux = a->first;
        while(aux != NULL){
            num_comp++;
            if(hlContainsLinear(b, (int)aux->data) == TRUE){
                printf("%d ",aux->data);
            }
            num_comp++;
            aux = aux->next;
        }
        num_comp++;
    }
}
