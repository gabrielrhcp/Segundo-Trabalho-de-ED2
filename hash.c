#include "hash.h"
#include "geral.h"
#define _HASH_C_

struct _hashOpen_{
	int currentSize;
	int maxSize;
	int * flags;
	int * keys;
	void ** vals;
};

HashOpen * hlCreate(int size, int dados){
	HashOpen * hl = (HashOpen*)malloc(sizeof(HashOpen));
	FILE *arq;
	int aux;

	if(hl != NULL){
		hl->currentSize = 0;
		hl->maxSize = size;
		hl->flags = calloc(size, sizeof(int));
		hl->keys = (int*)malloc(sizeof(int)*size);
		hl->vals = (void**)malloc(sizeof(void*)*size);

        if(dados == 1){  // se igual 1 lera o arquivo com os dados A, caso contrario dados B
            arq = fopen("dados/dadosA.txt","r");
        }else{
            arq = fopen("dados/dadosB.txt","r");
        }
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
		hl->vals = (void**)malloc(sizeof(void*)*hl->maxSize);
		return TRUE;
	}
	return FALSE;
}

int hlGetSize(HashOpen * hl){
	if(hl != NULL){
		return hl->currentSize;
	}
	return -1;
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

int hlInsertLinear(HashOpen * hl, int key, void * data){
	if(hl != NULL){
		int tmp = key % hl->maxSize;
		int i = tmp;
		do{
			if(hl->flags[i] == NULL){
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

void *hlGetLinear(HashOpen * hl, int key){
	if(hl != NULL){
		int i = key % hl->maxSize;
		while(hl->flags[i] == 1){
			if(hl->keys[i] == key){
				return hl->vals[i];
			}
			i = (i+1) % hl->maxSize;
		}
	}
	return NULL;
}

void *hlGetLinearValor(HashOpen * hl, int key, int valor){
	if(hl != NULL){
		int i = key % hl->maxSize;
		while(hl->flags[i] == 1){
			if(hl->vals[i] == valor){
				return hl->vals[i];
			}
			i = (i+1) % hl->maxSize;
		}
	}
	return NULL;
}

int hlContainsLinear(HashOpen * hl, int key){
	if(hlGetLinear(hl, key) != NULL){
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
		hl->vals[i] = NULL;
		i = (i + 1) % hl->maxSize;
		while(hl->flags[i] == 1){
			int keyT = hl->keys[i];
			void * dataT = hl->vals[i];
			hl->flags[i] = 0;
			hl->vals[i] = NULL;
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
				printf("%d|%d ",(int)hl->vals[i],hl->keys[i]);
			}
		}
	}
}

void hlIguais(HashOpen *a, HashOpen *b){
    if(a!= NULL && b!= NULL){
        for(int i = 0; i < a->maxSize; i++){
            if(a->flags[i] == 1){
                if(hlGetLinearValor(b, a->keys[i], (int)a->vals[i]) == a->vals[i]){
                    printf("%d ",(int)a->vals[i]);
                }
            }
        }
    }
}

