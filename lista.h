#ifndef _LIST_H_
#define _LIST_H_

typedef struct _dllelm_ DLNode;
typedef struct _dllist_ DLList;
DLList* sllCreate(int i);
int sllDestroy(DLList* list);
int dllInsertFirst(DLList *list, void *data);
void* dllQuery(DLList *list, void* key, int(*cmp)(void*,void*));
void* dllRemoveSpec(DLList *list, void* key, int(*cmp)(void*,void*));
int dllCmp(void * a, void * b);
void printLista(DLList *list);
void DLLprintIguais(DLList *a, DLList *b, int (*cmp)(void*,void*));
void DLLinserirListaBA(DLList *a, DLList *b, int(*cmp)(void*,void*));
void DLLremoverListaAB(DLList *a, DLList *b, int(*cmp)(void*,void*));

#endif // _LIST_H_

