#ifndef _HASHO_H_
#define _HASH_H_

typedef struct _hashOpen_ HashOpen;
HashOpen * hlCreate(int size, int dados);
int hlClear(HashOpen * hl);
int hlGetSize(HashOpen * hl);
int hlIsFull(HashOpen * hl);
int hlIsEmpty(HashOpen * hl);
int hlContains(HashOpen * hl, int key);
int hlInsertLinear(HashOpen * hl, int key, void * data);
void *hlGetLinear(HashOpen * hl, int key);
int hlRemoveLinear(HashOpen * hl, int key);
void hlPrint(HashOpen * hl);
#endif

