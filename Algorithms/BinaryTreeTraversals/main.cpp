#include "BinaryTreeTraversals.hpp"

int main() {
    /*
        This is the binary tree that has been created
                1
            2       3
        4       5       6
            7
    */
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->left->right = new TreeNode(7);
    root->right->right = new TreeNode(6);

    LevelOrderTraversal(root);
    InorderTraversal(root);
    PreOrderTraversal(root);
    PostOrderTraversal(root);
    MorrisTraversal(root);
    return 0;
}