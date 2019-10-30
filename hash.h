#include "lista.h"
#ifndef _HASH_H_
#define _HASH_H_

typedef struct _hashOpen_ HashOpen;
HashOpen * hlCreate(int size, char dados[]);
int hlClear(HashOpen * hl);
int hlGetSize(HashOpen * hl);
int hlIsFull(HashOpen * hl);
int * hlGetValues(HashOpen * hl);
int hlIsEmpty(HashOpen * hl);
int hlContainsLinear(HashOpen * hl, int key);
int hlHash(int key);
int hlInsertLinear(HashOpen * hl, int key, int data);
int hlGetLinear(HashOpen * hl, int key);
int hlRemoveLinear(HashOpen * hl, int key);
void hlPrint(HashOpen * hl);
void hlIguais(DLList *a, HashOpen *b);

#endif

