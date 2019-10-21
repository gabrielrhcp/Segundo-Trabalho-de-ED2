#include "avltree.h"
#include "rbtree.h"

int main(){
    // ARVORE AVL
    Node *avlA;
    Node *avlB;

    // ARVORE RUBRO NEGRA
    tipoArvore *rbA;
    tipoArvore *rbB;

    int ma; // metodo de armazenamento
    int oqf; // escolha feita pelo usuario, oq fazer


    printf("Escolha como armazenar:\n");
    printf("[1] Lista encadeada\n[2] Arvore binaria\n[3] Arvore AVL\n[4] Arvore rubro-negra\nDigite: ");
    scanf("%d",&ma);

    printf("O que voce quer fazer?\n");
    printf("[1] Buscar os elementos de A que estao em B\n");
    printf("[2] Inserir em B, os elementos de A que estão em B\n");
    printf("[3] Remover os elementos de A que estão em B\nDigite: ");
    scanf("%d",&oqf);

// lera o arquivo e armazenara de arcordo com a esolha feita
    switch(ma){
        case 1:

            break;
        case 2:

            break;

        case 3:
            avlA = createAvlTree(1);
            avlB = createAvlTree(2);
            printf("\nDados A: \n");
            preOrder(avlA);
            printf("\n\nDados B:\n");
            preOrder(avlB);
            switch(oqf){
                case 1:
                    printf("\n\nIguais:\n");
                    iguais(avlA, avlB);
                    printf("\n");
                    // 1 10 12 15 35 4 6 100 25 48 29 7
                    break;
                case 2:
                    // 2 3 24 8 36
                    printf("\n");
                    avlB = inserirBA(avlA, avlB);
                    printf("\nDados B com os elementos de A inseridos:\n");
                    preOrder(avlB);
                    printf("\n");
                    break;
                default:
                    //
                    printf("\n");
                    avlA = removeBA(avlB, avlA);
                    printf("\nRemovidos os elementos de A q tbm estao em B:\n");
                    preOrder(avlA);
                    printf("\n");
                    break;
            }
            break;

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
                    igualRB(rbA,rbB);
                    printf("\n");
                    // 1 10 12 15 35 4 6 100 25 48 29 7
                    break;
                case 2:
                    printf("\n");
                    rbB = inserirBARB(rbA, rbB);
                    printf("\nDados B com os elementos de A inseridos:\n");
                    preOrderRB(rbB);
                    printf("\n");
                    // 2 3 24 8 36
                    break;
                default:
                    printf("\n");
                    rbA = removerBARB(rbB, rbA);
                    printf("\nRemovidos os elementos de A q tbm estao em B:\n");
                    preOrderRB(rbA);
                    printf("\n");
                    //
                    break;
            }
            break;
    }
}

/*
            switch(oqf){
                case 1:
                    printf("\n\nIguais:\n");

                    printf("\n");
                    // 1 10 12 15 35 4 6 100 25 48 29 7
                    break;
                case 2:
                    printf("\n");

                    printf("\nDados B com os elementos de A inseridos:\n");

                    printf("\n");
                    break;
                    // 2 3 24 8 36
                    break;
                default:
                    printf("\n");

                    printf("\nRemovidos os elementos de A q tbm estao em B:\n");

                    printf("\n");
                    //
                    break;
            }

*/
