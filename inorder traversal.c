#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

void inOrder(struct TreeNode* tree) {
    if (tree != NULL) {
        inOrder(tree->left);
        printf("%d ", tree->data);
        inOrder(tree->right);
    }
}

int main() {
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->data = 1;
    
    root->left = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->left->data = 2;
    root->left->left = NULL;
    root->left->right = NULL;
    
    root->right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->right->data = 3;
    root->right->left = NULL;
    root->right->right = NULL;
    
    printf("In-order traversal: ");
    inOrder(root);
    
    free(root->left);
    free(root->right);
    free(root);
    
    return 0;
}
