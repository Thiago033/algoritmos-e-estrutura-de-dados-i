#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

void InOrder( struct TreeNode* root ) {
    if ( root == NULL ) return;
    
    InOrder(root->left);
    printf("%d -> ", root->val);
    InOrder(root->right);
}

void FreeTree( struct TreeNode* root ) {
    if ( root == NULL ) return;

    FreeTree( root->left );
    FreeTree( root->right );

    free( root );
}

int SubTreeHeight( struct TreeNode* root ) {
    if ( root == NULL) return 0;

    int leftHeight = SubTreeHeight( root->left );
    int rightHeight = SubTreeHeight( root->right );

    if ( leftHeight >= rightHeight ) {
        return (leftHeight + 1);
    } else {
        return (rightHeight + 1);
    }
}

/*
ARVORE EXEMPLO 1:
        1
    2       3
  4   5
*/

int DiameterOfBinaryTree( struct TreeNode* root ) {
    if ( root == NULL) return 0;

    int leftHeight = SubTreeHeight( root->left );
    int rightHeight = SubTreeHeight( root->right );

    int leftDiameter = DiameterOfBinaryTree(root->left);
    int rightDiameter = DiameterOfBinaryTree(root->right);

    int maxDiameter = leftDiameter > rightDiameter ? leftDiameter : rightDiameter;

    if ( (leftHeight + rightHeight) > maxDiameter ) {
        return (leftHeight + rightHeight);
    } else {
        return maxDiameter;
    }
}

int main(int argc, char const *argv[]) {
    //EXAMPLE 1:
    //Entrada: raiz = [1,2,3,4,5]
    // Saída: 3

    // Create tree root
    TreeNode *root = malloc( sizeof(TreeNode) );
    root->val = 1;
    root->left = NULL;  
    root->right = NULL;

    TreeNode *node2 = malloc( sizeof(TreeNode) );
    node2->val = 2;
    node2->left = NULL;
    node2->right = NULL;

    TreeNode *node3 = malloc( sizeof(TreeNode) );
    node3->val = 3;
    node3->left = NULL;
    node3->right = NULL;

    TreeNode *node4 = malloc( sizeof(TreeNode) );
    node4->val = 4;
    node4->left = NULL;
    node4->right = NULL;

    TreeNode *node5 = malloc( sizeof(TreeNode) );
    node5->val = 5;
    node5->left = NULL;
    node5->right = NULL;

    // Update pointers
    root->left = node2;
    root->right = node3;

    node2->left = node4;
    node2->right = node5;

    // -------------------------------------------------

    // // EXAMPLE 2:
    // // Entrada: raiz = [1,2]
    // // Saída: 1

    // // Create tree root
    // TreeNode *root = malloc( sizeof(TreeNode) );
    // root->val = 1;
    // root->left = NULL;
    // root->right = NULL;

    // TreeNode *node2 = malloc( sizeof(TreeNode) );
    // node2->val = 2;
    // node2->left = NULL;
    // node2->right = NULL;

    // // Update pointers
    // root->left = node2;

    // -------------------------------------------------
    
    // //EXAMPLE 3:
    // //Entrada: raiz = [1,2,3]
    // //Saída: 3

    // // Create tree root
    // TreeNode *root = malloc( sizeof(TreeNode) );
    // root->val = 1;
    // root->left = NULL;
    // root->right = NULL;

    // TreeNode *node2 = malloc( sizeof(TreeNode) );
    // node2->val = 2;
    // node2->left = NULL;
    // node2->right = NULL;

    // TreeNode *node3 = malloc( sizeof(TreeNode) );
    // node3->val = 3;
    // node3->left = NULL;
    // node3->right = NULL;

    // //Update pointers
    // root->left = node2;
    // root->right = node3;

    InOrder( root );
    printf("\n\n");

    int treeDiameter = DiameterOfBinaryTree( root );
    printf("Tree Diameter: %d", treeDiameter);

    FreeTree( root );

    return 0;
}
