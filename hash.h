#include "lista.h"
#ifndef _HASH_H_
#define _HASH_H_

typedef struct nb {
  void *data;
  int jumps;
  char flag ;
}Hash;

int hash_key(int aux);
Hash *Data_Create(int n, char a[]);
int Hash_insert(Hash *checker, void *aux, int checker_tam);
void Hash_FILE_Insert(Hash *Checker, int dados);
void *Hash_Search(Hash *checker, void *aux, int checker_tam);
void *Hash_Remove(Hash *checker, void *aux, int checker_tam);
void Show_Hash_list(Hash *checker,int checker_tam);
void hlIguais(DLList *a, Hash *b, int n);
void hlinserirListaBA(DLList *a, Hash *b, int n);
void hlremoverListaAB(DLList *a, Hash *b, int n);

#endif

