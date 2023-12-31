#ifndef BINARY_TREE_TRAVERSALS_H
#define BINARY_TREE_TRAVERSALS_H

struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int data) {
        this->value = data;
        this->left = nullptr;
        this->right = nullptr;
    };
    ~TreeNode();
};

void LevelOrderTraversal(TreeNode*);
void InorderTraversal(TreeNode*);
void inorderHelper(TreeNode*);
void PreOrderTraversal(TreeNode*);
void preorderHelper(TreeNode*);
void PostOrderTraversal(TreeNode*);
void postorderHelper(TreeNode*);
void MorrisTraversal(TreeNode*);
TreeNode* morrisTraversalFindPredecessor(TreeNode*);

#endif