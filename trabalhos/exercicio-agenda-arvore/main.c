#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

//Color definition for red-black tree
#define RED 1
#define BLACK 0

typedef struct node {
    char *name;
    int age;
    char *phone;

    char *key;

    //for avl tree
    int height;
    
    //for red-black tree
    int color;

    struct node* pLeft;
    struct node* pRight;

} node;


/*
==============================
    Global functions
==============================
*/

/*
===================================
isEmpty

    checks if the tree is empty
    return 1 if the tree is empty
    return 0 if not
===================================
*/
int isEmpty(node** root) {
    if (root == NULL) return 1;
    
    if (*root == NULL) return 1;

    return 0;
}

/*
===================================
freeNode

    free node
===================================
*/
void freeNode(node* node) {
    if (node == NULL) return;

    freeNode(node->pLeft);
    freeNode(node->pRight);
    free(node);

    node = NULL;
}

/*
===================================
freeTree

    free tree
===================================
*/
void freeTree(node** root) {
    if (root == NULL) return;

    freeNode(*root);

    free(root);    
}

/*
===================================
totalNodes

    total nodes
===================================
*/
int totalNodes(node** root) {
    node* rootPtr = *root;

    if (root == NULL) return 0;

    if (rootPtr == NULL) return 0;

    int totalLeft = totalNodes(&rootPtr->pLeft);
    int totalRight = totalNodes(&rootPtr->pRight);

    return (totalLeft + totalRight + 1);
}

/*
============================================
greater

    return the greater value between x and y
============================================
*/
int greater(int x, int y) {
    if (x > y) {
        return x;
    } else {
        return y;
    }
}

/*
=========================================
minValueNode

    find minimum value node and return it
=========================================
*/
struct node* minValueNode(struct node* node) {
    struct node* current = node;
  
    //loop down to find the leftmost leaf
    while (current && current->pLeft != NULL) {
        current = current->pLeft;
    }
        
    return current;
}

/*
===================================
find

    find a node in the tree
===================================
*/
node* find(node *root, char *key) {

    if (root == NULL) return NULL;

    if (strcmp(key, root->key) == 0) return root;

    //less than the root value
    if (strcmp(key, root->key) < 0) {
        return find(root->pLeft, key);
    } 

    //greater than the root value
    if (strcmp(key, root->key) > 0) {
        return find(root->pRight, key);
    }

    return NULL;
}

/*
===================================
preOrder

    pre order
===================================
*/
void preOrder(node* root) {
    if (root == NULL) return;

    printf("==========================\n");
    printf("Name: %s\n", root->name);
    printf("Age: %d\n", root->age);
    printf("Phone: %s\n", root->phone);
    preOrder(root->pLeft);
    preOrder(root->pRight);
}

/*
===================================
inOrder

    in order
===================================
*/
void inOrder(node* root) {
    if (root == NULL) return;

    inOrder(root->pLeft);
    printf("==========================\n");
    printf("Name: %s\n", root->name);
    printf("Age: %d\n", root->age);
    printf("Phone: %s\n", root->phone);
    inOrder(root->pRight);
}

/*
===================================
postOrder

    post order
===================================
*/
void postOrder(node* root) {
    if (root == NULL) return;

    postOrder(root->pLeft);
    postOrder(root->pRight);
    printf("==========================\n");
    printf("Name: %s\n", root->name);
    printf("Age: %d\n", root->age);
    printf("Phone: %s\n", root->phone);
}

/*
===================================
createNode

    create a new node
===================================
*/
node* createNode(char name[], int age, char phone[], int key) {

    node *newNode = malloc(sizeof(node));

    newNode->name = malloc(strlen(name));
    newNode->phone = malloc(strlen(phone));

    if (newNode != NULL) {
        strcpy(newNode->name, name);
        newNode->age = age;
        strcpy(newNode->phone, phone);

        newNode->pLeft = NULL;
        newNode->pRight = NULL;

        newNode->color = RED;
        newNode->height = 0;

        //defining the key
        if (key == 1) {
            newNode->key = (char *) malloc(strlen(name));

            strcpy(newNode->key, name);

        } else if (key == 2) {
            newNode->key = malloc(sizeof(age));

            sprintf(newNode->key, "%d", age);

        } else {
            newNode->key = (char *) malloc(strlen(phone));

            strcpy(newNode->key, phone);

        }
    }

    return newNode;
}



/*
==============================
    AVL Tree Functions
==============================
*/

/*
===================================
treeHeight

    tree height
===================================
*/
int treeHeight(node** root) {

    node* rootPtr = *root;

    if (root == NULL) return 0;

    if (rootPtr == NULL) return 0;

    int leftHeight = treeHeight(&rootPtr->pLeft);
    int rightHeight = treeHeight(&rootPtr->pRight);

    if (leftHeight > rightHeight) {
        return leftHeight + 1;
    } else {
        return rightHeight + 1;
    }
}

/*
===================================
nodeHeight

    node height
===================================
*/
int nodeHeight(node* node) {
    if (node == NULL) {
        return -1;
    } else {
        return node->height;
    }    
}

/*
===================================
balanceFactor

    balance factor
===================================
*/
int balanceFactor(node* node) {
    return labs(nodeHeight(node->pLeft) - nodeHeight(node->pRight));
}



/*
===================================
    AVL Tree Rotations
===================================
*/

/*
===================================
rotationLL

    rotation left
===================================
*/

void rotationLL(node **root){//LL

    struct node *node;

    node = (*root)->pLeft;

    (*root)->pLeft = node->pRight;

    node->pRight = *root;

    (*root)->height = greater(nodeHeight((*root)->pLeft),nodeHeight((*root)->pRight)) + 1;

    node->height = greater(nodeHeight(node->pLeft),(*root)->height) + 1;
    
    *root = node;
}

/*
===================================
rotationRR

    rotation right
===================================
*/

void rotationRR(node **root){//RR

    struct node *node;

    node = (*root)->pRight;

    (*root)->pRight = node->pLeft;

    node->pLeft = *root;

    (*root)->height = greater(nodeHeight((*root)->pLeft),nodeHeight((*root)->pRight)) + 1;

    node->height = greater(nodeHeight(node->pRight),(*root)->height) + 1;
    
    *root = node;
}

/*
===================================
rotationLR

    rotation LR
===================================
*/
void rotationLR(node** root) {
    node* rootPtr = *root;
    rotationRR(&rootPtr->pLeft);
    rotationLL(root);
}

/*
===================================
rotationRL

    rotation RL
===================================
*/
void rotationRL(node** root) {
    node* rootPtr = *root;
    rotationLL(&rootPtr->pRight);
    rotationRR(root);
}

/*
=========================================
insertAvlTree

    insert a new node into the AVL tree
=========================================
*/
bool insertAvlTree(node** root, node* newNode) {
    int res;

    if (*root == NULL) {
        *root = newNode;
        return true;
    }

    node *rootPtr = *root;

    //less than the root value
    if (strcmp(newNode->key, rootPtr->key) < 0) {

        if (insertAvlTree(&(rootPtr->pLeft), newNode)) {

            if (balanceFactor(rootPtr) >= 2) {

              //if (newNode->key < (*root)->pLeft->key) {
                res = strcmp(newNode->key, (*root)->pLeft->key);
                if (res < 0) {
                    rotationLL(root);
                } else {
                    rotationLR(root);
                }
            }
        }
    } 

    //greater than the root value
    if (strcmp(newNode->key, rootPtr->key) > 0) {
        
        if (insertAvlTree(&(rootPtr->pRight), newNode)) {

            if (balanceFactor(rootPtr) >= 2) {

              //if ((*root)->pRight->key < newNode->key) {
                if (strcmp((*root)->pRight->key, newNode->key) < 0) {
                    rotationRR(root);
                } else {
                    rotationRL(root);
                }
            }
        }
    }

    rootPtr->height = greater(nodeHeight(rootPtr->pLeft), nodeHeight(rootPtr->pRight)) + 1;

    return true;
}

/*
=========================================
removeNodeAvlTree

    remove a node
=========================================
*/
int removeNodeAvlTree(node** root, char* key) {

    if (*root == NULL) {
        printf("This value doesn't exist!\n");
        return 0;
    }

    int res;

    //if(key < (*root)->key) {
    if (strcmp(key, (*root)->key) < 0) {    

	    if((res = removeNodeAvlTree(&(*root)->pLeft,key)) == 1) {

            if(balanceFactor(*root) >= 2) {
                if(nodeHeight((*root)->pRight->pLeft) <= nodeHeight((*root)->pRight->pRight)) {
                    rotationRR(root);
                } else {
                    rotationLR(root);
                }
            }
	    }
	}

	//if((*root)->key < key) {
    if (strcmp((*root)->key, key) < 0) { 

	    if((res = removeNodeAvlTree(&(*root)->pRight, key)) == 1) {

            if(balanceFactor(*root) >= 2) {
                if(nodeHeight((*root)->pLeft->pRight) <= nodeHeight((*root)->pLeft->pLeft) ) {
                    rotationLL(root);
                } else {
                    rotationLR(root);
                }
            }
	    }
	}

	//if((*root)->key == key) {
    if (strcmp((*root)->key, key) == 0) {

	    if(((*root)->pLeft == NULL || (*root)->pRight == NULL)) {

			struct node *oldNode = (*root);

			if((*root)->pLeft != NULL) {
                *root = (*root)->pLeft;
            } else {
                *root = (*root)->pRight;
            }

			free(oldNode);

		} else {

			struct node* temp = minValueNode((*root)->pRight);

			(*root)->key = temp->key;

			removeNodeAvlTree(&(*root)->pRight, (*root)->key);

            if(balanceFactor(*root) >= 2){
				if(nodeHeight((*root)->pLeft->pRight) <= nodeHeight((*root)->pLeft->pLeft)) {
					rotationLL(root);
                } else {
					rotationLR(root);
                }
			}
		}
        
		if (*root != NULL)
            (*root)->height = greater(nodeHeight((*root)->pLeft),nodeHeight((*root)->pRight)) + 1;
		return 1;
	}

	(*root)->height = greater(nodeHeight((*root)->pLeft),nodeHeight((*root)->pRight)) + 1;

	return res;
}



/*
==============================
    Red-Black Tree Functions
==============================
*/

/*
===================================
color

    return node color
===================================
*/
int color(node* node) {
    if (node == NULL) {
        return BLACK;
    } else {
        return node->color;
    }
}

/*
===================================
changeColor

    change node color
===================================
*/
void changeColor(node* node) {
    node->color = !node->color;

    if (node->pLeft != NULL) {
        node->pLeft->color = !node->pLeft->color;
    }
    
    if (node->pRight != NULL){
        node->pRight->color = !node->pRight->color;
    }
}

/*
===================================
searchNode

    search node
===================================
*/
int searchNode(node** raiz, char* key){
    if(raiz == NULL)
        return 0;

    struct node* atual = *raiz;

    while(atual != NULL){

        if(strcmp(key, atual->key) == 0){
            return 1;
        }
        if(strcmp(key, atual->key) > 0)
            atual = atual->pRight;
        else
            atual = atual->pLeft;
    }
    return 0;
}

/*
===================================
    Red-Black Tree Rotations
===================================
*/

/*
===================================
rotationLeft

    rotation left
===================================
*/
node* rotationLeft(node* node) {
    struct node* nodePtr = node->pRight;

    node->pRight = nodePtr->pLeft;

    nodePtr->pLeft = node;

    nodePtr->color = node->color;

    node->color = RED;

    return nodePtr;
}

/*
===================================
rotationRight

    rotation right
===================================
*/
node* rotationRight(node* node) {
    struct node* nodePtr = node->pLeft;

    node->pLeft = nodePtr->pRight;

    nodePtr->pRight = node;

    nodePtr->color = node->color;

    node->color = RED;

    return nodePtr;
}

/*
===================================
moveToLeftRed

    move a red node to the left
===================================
*/
node* moveToLeftRed(node* node) {
    changeColor(node);

    if (color(node->pRight->pLeft) == RED) {
        node->pRight = rotationRight(node->pRight);

        node = rotationLeft(node);

        changeColor(node);
    }

    return node;
}

/*
===================================
moveToRightRed

    move a red node to the right
===================================
*/
node* moveToRightRed(node* node) {
    changeColor(node);

    if (color(node->pLeft->pLeft) == RED) {
        node = rotationRight(node);

        changeColor(node);
    }

    return node;
}

/*
===================================
balance

    balance tree
===================================
*/
node* balance(node* node) {

    if (color(node->pRight) == RED) {
        node = rotationLeft(node);
    }

    if (node->pLeft != NULL && color(node->pLeft) == RED && color(node->pLeft->pLeft) == RED) {
        node = rotationRight(node);
    }
    
    if (color(node->pLeft) == RED && color(node->pRight) == RED) {
        changeColor(node);
    }
    
    return node;
}

/*
=============================================
insertNode

    insert a new node into the Red-Black tree
=============================================
*/
node* insertNodeRedBlackTree(node* root, node* newNode, int* res) {

    if (root == NULL) {
        //struct node* newNode = createNode(data);

        if (newNode == NULL) {
            *res = 0;
            return NULL;
        }

        *res = 1;
        return newNode;
    }

    if (newNode->key == root->key) {
        *res = 0; //duplicated value
    } else {
        //less than the root value
        if (strcmp(newNode->key, root->key) < 0) {
            root->pLeft = insertNodeRedBlackTree(root->pLeft, newNode, res);
        } else {
            root->pRight = insertNodeRedBlackTree(root->pRight, newNode, res);
        }
    }

    if (color(root->pRight) == RED && color(root->pLeft) == BLACK) {
        root = rotationLeft(root);
    }
    
    if (color(root->pLeft) == RED && color(root->pLeft->pLeft) == RED) {
        root = rotationRight(root);
    }

    if (color(root->pLeft) == RED && color(root->pRight) == RED) {
        changeColor(root);
    }
     
    return root;
}

/*
===================================
insertRedBlackTree

    insert
===================================
*/
int insertRedBlackTree(node** root, node* newNode) {
    int res;

    //node* rootPtr = *root;

    (*root) = insertNodeRedBlackTree(*root, newNode, &res);

    if ((*root) != NULL) (*root)->color = BLACK;

    return res;
}

/*
===================================
removeMinimum

    removeMinimum
===================================
*/
struct node* removeMinimum(struct node* node){

    if(node->pLeft == NULL){
        free(node);
        return NULL;
    }

    if(color(node->pLeft) == BLACK && color(node->pLeft->pLeft) == BLACK){
        node = moveToLeftRed(node);
    }

    node->pLeft = removeMinimum(node->pLeft);

    return balance(node);
}

/*
===================================
removeNodeRedBlackTree

    remove node on red-black tree
===================================
*/
node* removeNodeRedBlackTree(node* root, char* key) {
    if (strcmp(key, root->key) < 0) {
        if (color(root->pLeft) == BLACK && color(root->pLeft->pLeft) == BLACK ) {
            root = moveToLeftRed(root);
        }

        root->pLeft = removeNodeRedBlackTree(root->pLeft, key);
    } else {
        if (color(root->pLeft) == RED) {
            root = rotationRight(root);
        }

        //if (key == root->key && (root->pRight == NULL)) {
        if (strcmp(key, root->key) == 0 && (root->pRight == NULL)) {
            free(root);
            return NULL;
        }

        if (color(root->pRight) == BLACK && color(root->pRight->pLeft) == BLACK) {
            root = moveToRightRed(root);
        }

        if (strcmp(key, root->key) == 0) {
            struct node* rootPtr = minValueNode(root->pRight);
            root->key = rootPtr->key;
            root->pRight = removeMinimum(root->pRight);
        } else {
            root->pRight = removeNodeRedBlackTree(root->pRight, key);
        }
    }

    return balance(root);
}

/*
===================================
remove

    remove
===================================
*/
int removeRedBlackTree(node** root, char* key) {
    if(searchNode(root, key)) {
        node* node = *root;

        *root = removeNodeRedBlackTree(node, key);

        if (*root != NULL) {
            (*root)->color = BLACK;
        }

        return 1;

    } else {
        return 0;
    }
}

/*
===================================
        MAIN FUNCTION
===================================
*/
int main(int argc, char const *argv[]) {
    
    //---------------------------------------------------
    //create root
    node *root = malloc(sizeof(node));

    if (root == NULL) {
        printf("Error!");
        exit(1);
    }

    root = NULL;
    //---------------------------------------------------

    int option, key, treeType, res;

	int age;
    char name[30], phone[20], searchKey[30];
	
    //defining key
    do
    {
        printf ("==========================\n");
        printf ("1 - name \n");
        printf ("2 - age \n");
        printf ("3 - phone \n");
        printf ("==========================\n");
        printf ("Key: ");
        scanf ("%d", &key);
    } while (key < 1 || key > 3);

    //defining tree type
    do
    {
        printf ("==========================\n");
        printf ("1 - AVL Tree              \n");
        printf ("2 - Red-Black Tree        \n");
        printf ("==========================\n");
        printf ("Key: ");
        scanf ("%d", &option);
    } while (option < 1 || option > 2);

    if (option == 1) {
        //tree type = AVL Tree
        treeType = 1;
    } else {
        //tree type = Red-Black Tree
        treeType = 0;
    }
    


    //======================= MANUAL INSERTS AVL TREE =======================

    // insertAvlTree(&root, createNode("a", 27, "an", key));
    // insertAvlTree(&root, createNode("b", 11, "bn", key));
    // insertAvlTree(&root, createNode("c", 19, "cn", key));
    // insertAvlTree(&root, createNode("d", 91, "dn", key));
    // insertAvlTree(&root, createNode("e", 90, "en", key));
    // insertAvlTree(&root, createNode("f", 72, "fn", key));

    // removeNodeAvlTree(&root, "11");
    // removeNodeAvlTree(&root, "72");

    // insertAvlTree(&root, createNode("g", 10, "gn", key));
    // insertAvlTree(&root, createNode("h", 93, "hn", key));

    //======================= MANUAL INSERTS AVL TREE =======================


    //======================= MANUAL INSERTS RED BLACK TREE =================

    // insertRedBlackTree(&root, createNode("a", 50, "an", key));
    // insertRedBlackTree(&root, createNode("b", 21, "bn", key));
    // insertRedBlackTree(&root, createNode("c", 85, "cn", key));
    // insertRedBlackTree(&root, createNode("d", 70, "cn", key));
    // insertRedBlackTree(&root, createNode("e", 20, "cn", key));
    // insertRedBlackTree(&root, createNode("f", 30, "cn", key));
    // insertRedBlackTree(&root, createNode("g", 15, "cn", key));

    // removeRedBlackTree(&root, "15");

    //======================= MANUAL INSERTS RED BLACK TREE =================


    do {
        printf ("==========================\n");
        printf("1) Insert       \n");
        printf("2) Delete       \n");
        printf("3) Print        \n");
        printf("4) Search       \n");
        printf("5) Tree Stats   \n");
        printf("6) Quit         \n");
        printf ("==========================\n");
        scanf("%d", &option);
        
        switch (option) {

        case 1:
            //INSERT

            printf("Insert data:    \n");
            printf("Name:           \n");
            scanf("%s", name           );
            printf("Age:            \n");
            scanf("%d", &age           );
            printf("Phone number:   \n");
            scanf("%s", phone          );

            if (treeType) {
                insertAvlTree(&root, createNode(name, age, phone, key));
            } else {
                insertRedBlackTree(&root, createNode(name, age, phone, key));
            }

            break;

        case 2:
            //DELETE

            if (isEmpty(&root)) {
                printf("Tree is empty!\n");
                break;
            }

            printf("Type the key: \n");
            scanf("%s", searchKey);

            if (treeType) {
                res = removeNodeAvlTree(&root, searchKey);
            } else {
                res = removeRedBlackTree(&root, searchKey);
            }
            
            if (res) {
                printf("Data removed!\n");
            } else {
                printf("Data not founded!\n");
            }
            	
            break;

        case 3:
            //PRINT
            
            if (isEmpty(&root)) {
                printf("Tree is empty!\n");
                break;
            }

            do {
                printf ("==========================\n");
				printf ("Print tipe:    \n");
				printf ("1 - Post Order  \n");
				printf ("2 - In Order   \n");
				printf ("3 - Pre Order \n");
				scanf ("%d", &option);
                printf ("==========================\n");

                switch(option) {

                case 1:
                    printf("Post Order: \n");
                    postOrder(root);
                    break;

                case 2:
                    printf("In Order: \n");
                    inOrder(root);
                    break;

                case 3:
                    printf("Pre Order: \n");
                    preOrder(root);
                    break;
                
                default:
                    printf("Invalid option! try again!\n");
                    break;
                }
			} while (option < 1 || option > 3);

            break;
        
        case 4:
            //SEARCH
            if (isEmpty(&root)) {
                printf("Tree is empty!\n");
                break;
            }

            printf("Type the key: \n");
            scanf("%s", searchKey);

            node* searchNode = find(root, searchKey);

            if (searchNode != NULL) {
                printf("==========================\n");
                printf("Data founded:\n\n");
                printf("Name: %s\n", searchNode->name);
                printf("Age: %d\n", searchNode->age);
                printf("Phone: %s\n", searchNode->phone);
                printf("==========================\n");
            } else {
                printf("Data not found!\n");
            }

            break;
        
        case 5:
            //PRINT TREE STATS
            printf("\nTREE HEIGHT\n");
            printf("%d\n", treeHeight(&root));

            printf("TOTAL NODES\n");
            printf("%d\n", totalNodes(&root));

            printf("MINIMUM NODE\n");
            if (isEmpty(&root)) {
                printf("Tree is empty!\n\n");
            } else {
                node* minimumNode = minValueNode(root);
                printf("%s\n\n", minimumNode->key);
            }
            
            printf("TREE IS EMPTY?\n");
            if (isEmpty(&root)) {
                printf("Tree is empty!\n\n");
            } else {
                printf("Tree isn't empty!\n\n");
            }

            break;
        
        case 6:
            //QUIT

            printf("Quit.\n");
            return 0;
            break;
        
        default:
            printf("Invalid option! try again!\n");
            break;
        }

    } while (option != 6);

    return 0;
}