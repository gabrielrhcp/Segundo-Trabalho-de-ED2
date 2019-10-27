#include "geral.h"
#include "avltree.h"
#include "rbtree.h"
#include "btree.h"
#include "lista.h"


int main(){

    // LISTA
    DLList *listA;
    DLList *listB;

    // ARVORE BINARIA
    t_arvore btA;
    t_arvore btB;

    // ARVORE AVL
    Node *avlA;
    Node *avlB;

    // ARVORE RUBRO NEGRA
    tipoArvore *rbA;
    tipoArvore *rbB;

    int ma; // metodo de armazenamento
    int oqf; // escolha feita pelo usuario, oq fazer
    time_t t_ini = 0 , t_fim = 0;


    printf("Escolha como armazenar:\n");
    printf("[1] Lista encadeada\n[2] Hash\n[3] Arvore binaria\n[4] Arvore AVL\n[5] Arvore rubro-negra\nDigite: ");
    scanf("%d",&ma);

    printf("O que voce quer fazer?\n");
    printf("[1] Buscar os elementos de A que estao em B\n");
    printf("[2] Inserir em B, os elementos de A que estão em B\n");
    printf("[3] Remover os elementos de A que estão em B\nDigite: ");
    scanf("%d",&oqf);

// lera o arquivo e armazenara de arcordo com a esolha feita
    switch(ma){

        // LISTA ENCADEADA
        case 1:
            listA = dllCreate(1);
            listB = dllCreate(2);
            printf("\nDados A: \n");
            printLista(listA);
            printf("\n\nDados B: \n");
            printLista(listB);

            switch(oqf){
                case 1:
                    printf("\n\nIguais:\n");
                    t_ini = time(NULL);
                    DLLprintIguais(listA, listB, dllCmp);
                    t_fim = time(NULL);
                    printf("\n");
                    // 1 10 12 15 35 4 6 100 25 48 29 7
                    break;
                case 2:
                    printf("\n");
                    t_ini = time(NULL);
                    DLLinserirListaBA(listA,listB,dllCmp);
                    t_fim = time(NULL);
                    printf("\nDados B com os elementos de A inseridos:\n");
                    printLista(listB);
                    printf("\n");
                    break;
                    // 2 3 24 8 36
                    break;
                default:
                    printf("\n");
                    t_ini = time(NULL);
                    DLLremoverListaAB(listB, listA, dllCmp);
                    t_fim = time(NULL);
                    printf("\nRemovidos os elementos de A q tbm estao em B:\n");
                    printLista(listA);
                    printf("\n");
                    // 8 2 3 24 36
                    break;
            }
            break;

        // ARVORE BINARIA
        case 3:
            btA = criaNoBT(1);
            btB = criaNoBT(2);
            printf("\nDados A: \n");
            exibirPreOrdem(btA);
            printf("\n\nDados B: \n");
            exibirPreOrdem(btB);

            switch(oqf){
                case 1:
                    printf("\n\nIguais:\n");
                    t_ini = time(NULL);
                    iguaisBT(btA, btB);
                    t_fim = time(NULL);
                    printf("\n");
                    // 1 10 12 15 35 4 6 100 25 48 29 7
                    break;
                case 2:
                    printf("\n");
                    t_ini = time(NULL);
                    btB = inserirBABT(btA, btB);
                    t_fim = time(NULL);
                    printf("\nDados B com os elementos de A inseridos:\n");
                    exibirPreOrdem(btB);
                    printf("\n");
                    break;
                    // 2 3 24 8 36
                    break;
                default:
                    printf("\n");
                    t_ini = time(NULL);
                    btA = removerABBT(btB, btA);
                    t_fim = time(NULL);
                    printf("\nRemovidos os elementos de A q tbm estao em B:\n");
                    exibirPreOrdem(btA);
                    printf("\n");
                    // 8 2 3 24 36
                    break;
            }
            break;

        // ARVORE AVL
        case 4:
            avlA = createAvlTree(1);
            avlB = createAvlTree(2);
            printf("\nDados A: \n");
            preOrder(avlA);
            printf("\n\nDados B:\n");
            preOrder(avlB);
            switch(oqf){
                case 1:
                    printf("\n\nIguais:\n");
                    t_ini = time(NULL);
                    iguais(avlA, avlB);
                    t_fim = time(NULL);
                    printf("\n");
                    // 1 10 12 15 35 4 6 100 25 48 29 7
                    break;
                case 2:
                    // 2 3 24 8 36
                    printf("\n");
                    t_ini = time(NULL);
                    avlB = inserirBA(avlA, avlB);
                    t_fim = time(NULL);
                    printf("\nDados B com os elementos de A inseridos:\n");
                    preOrder(avlB);
                    printf("\n");
                    break;
                default:
                    // 8 2 3 24 36
                    printf("\n");
                    t_ini = time(NULL);
                    avlA = removeBA(avlB, avlA);
                    t_fim = time(NULL);
                    printf("\nRemovidos os elementos de A q tbm estao em B:\n");
                    preOrder(avlA);
                    printf("\n");
                    break;
            }
            break;

        // ARVORE RUBRO NEGRA
        default:
            criarArvoreRB(&rbA,1);
            criarArvoreRB(&rbB,0);
            printf("\nDados A: \n");
            preOrderRB(rbA);
            printf("\n\nDados B: \n");
            preOrderRB(rbB);

            switch(oqf){
                case 1:
                    printf("\n\nIguais:\n");
                    t_ini = time(NULL);
                    igualRB(rbA,rbB);
                    t_fim = time(NULL);
                    printf("\n");
                    // 1 10 12 15 35 4 6 100 25 48 29 7
                    break;
                case 2:
                    printf("\n");
                    t_ini = time(NULL);
                    rbB = inserirBARB(rbA, rbB);
                    t_fim = time(NULL);
                    printf("\nDados B com os elementos de A inseridos:\n");
                    preOrderRB(rbB);
                    printf("\n");
                    // 2 3 24 8 36
                    break;
                default:
                    printf("\n");
                    t_ini = time(NULL);
                    rbA = removerBARB(rbB, rbA);
                    t_fim = time(NULL);
                    printf("\nRemovidos os elementos de A q tbm estao em B:\n");
                    preOrderRB(rbA);
                    printf("\n");
                    // 8 2 3 24 36
                    break;
            }
            break;
    }

    printf("\n\nTempo: %f\n",difftime(t_fim, t_ini));
}

/*


            printf("\nDados A: \n");

            printf("\n\nDados B: \n");


            switch(oqf){
                case 1:
                    printf("\n\nIguais:\n");
                    t_ini = time(NULL);

                    t_fim = time(NULL);
                    printf("\n");
                    // 1 10 12 15 35 4 6 100 25 48 29 7
                    break;
                case 2:
                    printf("\n");
                    t_ini = time(NULL);

                    t_fim = time(NULL);
                    printf("\nDados B com os elementos de A inseridos:\n");

                    printf("\n");
                    break;
                    // 2 3 24 8 36
                    break;
                default:
                    printf("\n");
                    t_ini = time(NULL);

                    t_fim = time(NULL);
                    printf("\nRemovidos os elementos de A q tbm estao em B:\n");

                    printf("\n");
                    //
                    break;
            }

*/
