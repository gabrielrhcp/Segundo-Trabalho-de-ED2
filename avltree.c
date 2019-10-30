#include "geral.h"
#include "avltree.h"
#define _AVLTREE_C_

// An AVL tree node
struct node_tree
{
	int key;
	Node *left;
	Node *right;
	int height;
};

// node = insert(node, key); -- assim q insere
// node = deleteNode(node, key); -- assim q deleta
// preOrder(node); -- assim q printa
Node* createAvlTree(char a[]){
    Node *root = NULL;
    FILE *arq;
    arq = fopen(a,"r");
    int aux;

    while(fscanf(arq,"%d",&aux) != EOF){
        root = insertCricao(root, aux);
    }
    fclose(arq);

    return root;
}

Node* insert(Node* node, int key)
{
    num_comp++;
	if (node == NULL)
		return(newNode(key));

    num_comp++;
	if (key < node->key)
		node->left = insert(node->left, key);
	else if (++num_comp && key > node->key)
		node->right = insert(node->right, key);
	else
		return node;


	node->height = 1 + max(height(node->left),
						height(node->right));

	int balance = getBalance(node);

	num_comp+=2;
	if (balance > 1 && key < node->left->key){
        return rightRotate(node);
	}


	num_comp+=2;
	if (balance < -1 && key > node->right->key){
        return leftRotate(node);
	}


	num_comp+=2;
	if (balance > 1 && key > node->left->key)
	{
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}

	num_comp+=2;
	if (balance < -1 && key < node->right->key)
	{
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}

	/* return the (unchanged) node pointer */
	return node;
}


// A utility function to get height of the tree
int height(Node *N)
{
    num_comp++;
	if (N == NULL)
		return 0;
	return N->height;
}

int heightCriacao(Node *N)
{
	if (N == NULL)
		return 0;
	return N->height;
}

// A utility function to get maximum of two integers
int maxCriacao(int a, int b)
{
	return (a > b)? a : b;
}

int max(int a, int b)
{
    num_comp++;
	return (a > b)? a : b;
}

/* Helper function that allocates a new node with the given key and
	NULL left and right pointers. */
Node* newNode(int key)
{
    Node* node = (Node*)malloc(sizeof(Node));
	node->key = key;
	node->left = NULL;
	node->right = NULL;
	node->height = 1; // new node is initially added at leaf
	return(node);
}

Node* newNodeCriacao(int key)
{
    Node* node = (Node*)malloc(sizeof(Node));
	node->key = key;
	node->left = NULL;
	node->right = NULL;
	node->height = 1; // new node is initially added at leaf
	return(node);
}

// A utility function to right rotate subtree rooted with y
// See the diagram given above.
Node *rightRotateCriacao(Node *y)
{
	Node *x = y->left;
	Node *T2 = x->right;

	// Perform rotation
	x->right = y;
	y->left = T2;

	// Update heights
	y->height = max(height(y->left), height(y->right))+1;
	x->height = max(height(x->left), height(x->right))+1;

	// Return new root
	return x;
}

Node *rightRotate(Node *y)
{
	Node *x = y->left;
	Node *T2 = x->right;

	// Perform rotation
	x->right = y;
	y->left = T2;

	// Update heights
	y->height = max(height(y->left), height(y->right))+1;
	x->height = max(height(x->left), height(x->right))+1;

	// Return new root
	return x;
}

// A utility function to left rotate subtree rooted with x
// See the diagram given above.
Node *leftRotateCriacao(Node *x)
{
	Node *y = x->right;
	Node *T2 = y->left;

	// Perform rotation
	y->left = x;
	x->right = T2;

	// Update heights
	x->height = max(height(x->left), height(x->right))+1;
	y->height = max(height(y->left), height(y->right))+1;

	// Return new root
	return y;
}

Node *leftRotate(Node *x)
{
	Node *y = x->right;
	Node *T2 = y->left;

	// Perform rotation
	y->left = x;
	x->right = T2;

	// Update heights
	x->height = max(height(x->left), height(x->right))+1;
	y->height = max(height(y->left), height(y->right))+1;

	// Return new root
	return y;
}

// Get Balance factor of node N
int getBalance(Node *N)
{
    num_comp++;
	if (N == NULL)
		return 0;
	return height(N->left) - height(N->right);
}

int getBalanceCriacao(Node *N)
{
	if (N == NULL)
		return 0;
	return height(N->left) - height(N->right);
}

Node* insertCricao(Node* node, int key)
{
	if (node == NULL)
		return(newNodeCriacao(key));

	if (key < node->key)
		node->left = insertCricao(node->left, key);
	else if (key > node->key)
		node->right = insertCricao(node->right, key);
	else
		return node;


	node->height = 1 + maxCriacao(height(node->left),
						heightCriacao(node->right));

	int balance = getBalanceCriacao(node);
	if (balance > 1 && key < node->left->key){
        return rightRotateCriacao(node);
	}

	if (balance < -1 && key > node->right->key){
        return leftRotateCriacao(node);
	}

	if (balance > 1 && key > node->left->key)
	{
		node->left = leftRotateCriacao(node->left);
		return rightRotateCriacao(node);
	}

	if (balance < -1 && key < node->right->key)
	{
		node->right = rightRotateCriacao(node->right);
		return leftRotateCriacao(node);
	}

	return node;
}

/* Given a non-empty binary search tree, return the
node with minimum key value found in that tree.
Note that the entire tree does not need to be
searched. */
Node *minValueNode(Node *node)
{
	Node* current = node;

	/* loop down to find the leftmost leaf */
	while (current->left != NULL)
		current = current->left;

	return current;
}

void preOrder(Node *root)
{
	if(root != NULL)
	{
		printf("%d ", root->key);
		preOrder(root->left);
		preOrder(root->right);
	}
}

int compara(int a, Node *b)
{
    num_comp++;
    if(b != NULL)
	{
	    num_comp++;
	    if(a == b->key)
        {
            return TRUE;
	    }
	    num_comp+=2;
	    if(compara(a, b->left) != TRUE && compara(a, b->right) != TRUE)
        {
            return FALSE;
        }
        else
        {
            return TRUE;
        }
        num_comp++;
	}
}

void iguaisAVL(DLList *a, Node *b)
{
	DLNode *aux;
	num_comp+=2;
    if(a != NULL && b != NULL){
        aux = a->first;
        while(aux != NULL){
            num_comp++;
            if(compara((int)aux->data,b) != NULL){
                printf("%d ",(int)aux->data);
            }
            num_comp++;
            aux = aux->next;
        }
        num_comp++;
    }
}

void inserirBA(DLList *a, Node *b)
{
    DLNode *aux;
    num_comp+=2;
    if(a != NULL && b != NULL){
        aux = a->first;
        while(aux != NULL){
            num_comp++;
            if(compara((int)aux->data,b) == NULL){
                b = insert(b,(int)aux->data);
            }
            num_comp++;
            aux = aux->next;
        }
        num_comp++;
    }
}

DLList *removeBA(DLList *a, Node *b)
{
    DLNode *aux;
    DLList *blz = dllCreate(NULL);
    num_comp+=2;
    if(a != NULL && b != NULL){
        aux = a->first;
        while(aux != NULL){
            num_comp++;
            if(compara((int)aux->data,b) == NULL){
                dllInsertFirst(blz, aux->data);
            }
            num_comp++;
            aux = aux->next;
        }
        num_comp++;
    }
    return blz;
}
