#include "hash.h"
#include "geral.h"
#define _HASH_C_

int hash_key(int aux){
  return aux % 7;
}

Hash *Data_Create(int n, char a[]){
    Hash* aux = (Hash*)malloc(n*sizeof(Hash));
    FILE *arquivo;
    int valor;

    if(a != NULL){
        arquivo = fopen(a, "r");
        while(fscanf(arquivo,"%d",&valor) != EOF){
            Hash_insert(aux, (void*)valor,n);
        }
        fclose(arquivo);
	}
	return aux;
}

int Hash_insert(Hash *checker, void *aux, int checker_tam){
    int pos = hash_key(aux);
    if(checker[pos].flag != 'T'){
        checker[pos].data = malloc(20);
        checker[pos].data = aux;
        checker[pos].jumps = 0;
        checker[pos].flag = 'T';

        if(checker[pos].data == aux){
            return 1;
        }
        checker[pos].flag = 'F';
        printf("Insert error \n");
    }else if(checker[pos].data != aux){
        int aux2 = pos+1;
        while(aux2 < checker_tam && checker[aux2].flag == 'T' && checker[aux2].data != aux){
            aux2++;
        }
        if(aux2 < checker_tam && checker[aux2].flag != 'T'){
            checker[aux2].data = malloc(1);
            checker[aux2].data = aux;
            checker[aux2].jumps = aux2-pos;
            checker[aux2].flag = 'T';

            return 1;
        }
        printf("Space not found %d %d\n", pos , aux);
    }
        return 0;
}

void Hash_FILE_Insert(Hash *Checker, int dados){
    FILE *arq;
    if(dados == 1){  // se igual 1 lera o arquivo com os dados A, caso contrario dados B
        arq = fopen("dados/dadosA.txt","r");
    }else{
        arq = fopen("dados/dadosB.txt","r");
    }
    int aux;

    while(fscanf(arq,"%d",&aux) != EOF){
        Hash_insert(Checker, aux, 100);
    }
    fclose(arq);
}
void *Hash_Search(Hash *checker, void *aux, int checker_tam){
    int pos = hash_key(aux);
    if(checker[pos].data != NULL && checker[pos].flag == 'T'){
        if(checker[pos].data == aux){
            return checker[pos].data;
        }
    }
    int aux2 = pos+1;
    int stat = -1;
    while(aux2 < checker_tam && stat != 0){
        if(checker[aux2].data != NULL && checker[aux2].flag == 'T'){
            if((int)checker[aux2].data == aux){
                stat = 0;
            }
        }if(stat != 0){
            aux2++;
        }
    }
    if(stat == 0){
        return checker[aux2].data;
    }
    return NULL;
}

void *Hash_Remove(Hash *checker, void *aux, int checker_tam){
    int pos = hash_key(aux);
    if(checker[pos].data != NULL && checker[pos].flag != 'F'){
        if(checker[pos].data == aux){
            void *temp = checker[pos].data;
            checker[pos].flag = 'F';
            return temp;
        }
    }
    int aux2 = pos+1;
    int stat = -1;
    while(aux2 < checker_tam && stat != 0){
      if(checker[aux2].data != NULL && checker[aux2].flag != 'F'){
        if((int)checker[aux2].data == aux){
          stat = 0;
        }
      }
      if(stat != 0){
          aux2++;
      }
    }
    if(stat == 0){
      void *temp = checker[aux2].data;
      checker[aux2].flag = 'F';
      return temp;
    }
  return NULL;
}

void Show_Hash_list(Hash *checker,int checker_tam){
  int aux = 0;
  while(aux < checker_tam-1){
    if(checker[aux].flag == 'T' && checker[aux].data != NULL){
      printf("%d ", checker[aux].data);
    }
    aux++;
  }
}

void hlIguais(DLList *a, Hash *b, int n){
    DLNode *aux;
    if(a != NULL && b != NULL){
        aux = a->first;
        while(aux != NULL){
            num_comp++;
            if(Hash_Search(b, aux->data,n) != NULL){
                printf("%d ",aux->data);
            }
            num_comp++;
            aux = aux->next;
        }
        num_comp++;
    }
}

void hlinserirListaBA(DLList *a, Hash *b, int n){
    DLNode *aux;
    num_comp+=2;
    if(a != NULL && b != NULL){
        aux = a->first;
        while(aux != NULL){
            num_comp++;
            if(Hash_Search(b, aux->data,n) == NULL){
                Hash_insert(b, aux->data,n);
            }
            num_comp++;
            aux = aux->next;
        }
        num_comp++;
    }
}

void hlremoverListaAB(DLList *a, Hash *b, int n){
    DLNode *aux;
    num_comp+=2;
    if(a != NULL && b != NULL){
        aux = a->first;
        while(aux != NULL){
            num_comp++;
            if(Hash_Search(b, aux->data,n) != NULL){
               dllRemoveSpec(a,aux->data,dllCmp);
            }
            num_comp++;
            aux = aux->next;
        }
        num_comp++;
    }
}
