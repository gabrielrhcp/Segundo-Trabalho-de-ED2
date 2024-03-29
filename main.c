#include "geral.h"
#include "avltree.h"
#include "rbtree.h"
#include "btree.h"
#include "lista.h"
#include "hash.h"

int main(){
    // VARIAVEIS AUXILIARES
    num_comp = 0;
    num_atb = 0;

    // LISTA
    DLList *list;
    DLList *list2;

    // HASH
    Hash *hash;

    // ARVORE BINARIA
    node *bt;

    // ARVORE AVL
    Node *avl;

    // ARVORE RUBRO NEGRA
    tipoArvore *rb;

    int ma; // metodo de armazenamento
    int oqf; // escolha feita pelo usuario, oq fazer
    time_t t_ini = 0 , t_fim = 0;
    char dadosB[] = "dados/dadosB.txt";
    int menu_control;

    do{
        list = dllCreate("dados/dadosA.txt");
        num_comp = 0;
        num_atb = 0;
        system("cls");
        printf("Escolha como armazenar:\n");
        printf("[1] Lista encadeada\n[2] Hash\n[3] Arvore binaria\n[4] Arvore AVL\n[5] Arvore rubro-negra\nDigite: ");
        scanf("%d",&ma);

        printf("O que voce quer fazer?\n");
        printf("[1] Buscar os elementos de A que estao em B\n");
        printf("[2] Inserir em B, os elementos de A que estao em B\n");
        printf("[3] Remover os elementos de A que est�o em B\nDigite: ");
        scanf("%d",&oqf);

    // lera o arquivo e armazenara de arcordo com a esolha feita
        switch(ma){

            // LISTA ENCADEADA
            case 1:
                list2 = dllCreate(dadosB);
                printf("\nDados A: \n");
                printLista(list);
                printf("\n\nDados B: \n");
                printLista(list2);

                switch(oqf){
                    case 1:
                        printf("\n\nIguais:\n");
                        t_ini = time(NULL);
                        DLLprintIguais(list, list2, dllCmp);
                        t_fim = time(NULL);
                        printf("\n");
                        // 1 10 12 15 35 4 6 100 25 48 29 7
                        break;
                    case 2:
                        printf("\n");
                        t_ini = time(NULL);
                        DLLinserirListaBA(list,list2,dllCmp);
                        t_fim = time(NULL);
                        printf("\nDados B com os elementos de A inseridos:\n");
                        printLista(list2);
                        printf("\n");
                        break;
                        // 2 3 24 8 36
                        break;
                    default:
                        printf("\n");
                        t_ini = time(NULL);
                        DLLremoverListaAB(list2, list, dllCmp);
                        t_fim = time(NULL);
                        printf("\nRemovidos os elementos de A q tbm estao em B:\n");
                        printLista(list);
                        printf("\n");
                        // 8 2 3 24 36
                        break;
                }
                break;

            // HASH
            case 2:
                hash = Data_Create(100, dadosB);
                printf("\nDados A: \n");
                printLista(list);
                printf("\n\nDados B(key|chave):\n");
                Show_Hash_list(hash,100);

                switch(oqf){
                    case 1:
                        printf("\n\nIguais:\n");
                        t_ini = time(NULL);
                        hlIguais(list, hash,100);
                        t_fim = time(NULL);
                        printf("\n");
                        // 1 10 12 15 35 4 6 100 25 48 29 7
                        break;
                    case 2:
                        printf("\n");
                        t_ini = time(NULL);
                        hlinserirListaBA(list, hash,100);
                        t_fim = time(NULL);
                        printf("\nDados B com os elementos de A inseridos:\n");
                        Show_Hash_list(hash,100);
                        printf("\n");
                        break;
                        // 2 3 24 8 36
                        break;
                    default:
                        printf("\n");
                        t_ini = time(NULL);
                        hlremoverListaAB(list, hash,100);
                        t_fim = time(NULL);
                        printf("\nRemovidos os elementos de A q tbm estao em B:\n");
                        printLista(list);
                        printf("\n");
                        // 8 2 3 24 36
                        break;
                }
                break;

            // ARVORE BINARIA
            case 3:
                bt = criarAB(dadosB);
                printf("\nDados A: \n");
                printLista(list);
                printf("\n\nDados B: \n");
                preAB(bt);

                switch(oqf){
                    case 1:
                        printf("\n\nIguais:\n");
                        t_ini = time(NULL);
                        iguaisAB(list, bt);
                        t_fim = time(NULL);
                        printf("\n");
                        // 1 10 12 15 35 4 6 100 25 48 29 7
                        break;
                    case 2:
                        printf("\n");
                        t_ini = time(NULL);
                        inserirBAAB(list, bt);
                        t_fim = time(NULL);
                        printf("\nDados B com os elementos de A inseridos:\n");
                        preAB(bt);
                        printf("\n");
                        break;
                        // 2 3 24 8 36
                        break;
                    default:
                        printf("\n");
                        t_ini = time(NULL);
                        list = removerABAB(list, bt);
                        t_fim = time(NULL);
                        printf("\nRemovidos os elementos de A q tbm estao em B:\n");
                        printLista(list);
                        printf("\n");
                        // 8 2 3 24 36
                        break;
                }
                break;

            // ARVORE AVL
            case 4:
                avl = createAvlTree(dadosB);
                printf("\nDados A: \n");
                printLista(list);
                printf("\n\nDados B:\n");
                preOrder(avl);
                switch(oqf){
                    case 1:
                        printf("\n\nIguais:\n");
                        t_ini = time(NULL);
                        iguaisAVL(list, avl);
                        t_fim = time(NULL);
                        printf("\n");
                        // 1 10 12 15 35 4 6 100 25 48 29 7
                        break;
                    case 2:
                        // 2 3 24 8 36
                        printf("\n");
                        t_ini = time(NULL);
                        inserirBAAVL(list, avl);
                        t_fim = time(NULL);
                        printf("\nDados B com os elementos de A inseridos:\n");
                        preOrder(avl);
                        printf("\n");
                        break;
                    default:
                        // 8 2 3 24 36
                        printf("\n");
                        t_ini = time(NULL);
                        list = removeBAAVL(list, avl);
                        t_fim = time(NULL);
                        printf("\nRemovidos os elementos de A q tbm estao em B:\n");
                        printLista(list);
                        printf("\n");
                        break;
                }
                break;

            // ARVORE RUBRO NEGRA
            default:
                criarArvoreRB(&rb,dadosB);
                printf("\nDados A: \n");
                printLista(list);
                printf("\n\nDados B: \n");
                preOrderRB(rb);

                switch(oqf){
                    case 1:
                        printf("\n\nIguais:\n");
                        t_ini = time(NULL);
                        igualRB(list,rb);
                        t_fim = time(NULL);
                        printf("\n");
                        // 1 10 12 15 35 4 6 100 25 48 29 7
                        break;
                    case 2:
                        printf("\n");
                        t_ini = time(NULL);
                        inserirBARB(list, rb);
                        t_fim = time(NULL);
                        printf("\nDados B com os elementos de A inseridos:\n");
                        preOrderRB(rb);
                        printf("\n");
                        // 2 3 24 8 36
                        break;
                    default:
                        printf("\n");
                        t_ini = time(NULL);
                        list = removerBARB(list, rb);
                        t_fim = time(NULL);
                        printf("\nRemovidos os elementos de A q tbm estao em B:\n");
                        printLista(list);
                        printf("\n");
                        // 8 2 3 24 36
                        break;
                }
                break;
        }
        printf("\nTempo de execucao: %f\n",difftime(t_fim, t_ini));
        printf("\nNumero de comparacoes: %d\n",num_comp);
        printf("Numero de atribuicoes: %d\n",num_atb);

        printf("\nDeseja continuar?\n[1] Sim\n[2] Nao\nDigite: ");
        scanf("%d",&menu_control);
    }while(menu_control == 1);
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
                    // 8 2 3 24 36
                    break;
            }

*/
