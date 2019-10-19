#include "avltree.h"

int main(){
    Node *dadosA;
    Node *dadosB;
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
            dadosA = createAvlTree(1);
            dadosB = createAvlTree(2);
            break;
        default:

            break;
    }

    printf("\nDados A: \n");
    preOrder(dadosA);
    printf("\n\nDados B:\n");
    preOrder(dadosB);

    switch(oqf){
        case 1:
            printf("\n\nIguais: ");
            iguais(dadosA, dadosB);
            printf("\n");
            // 1 10 12 15 35 4 6 100 25 48 29 7
            break;
        case 2:

            break;
        default:

            break;
    }
}
