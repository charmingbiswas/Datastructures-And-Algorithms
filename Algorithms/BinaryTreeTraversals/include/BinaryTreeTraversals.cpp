#include "BinaryTreeTraversals.hpp"

#include <iostream>
#include <queue>

void LevelOrderTraversal(TreeNode* root) {
    std::cout << "Level order traversal started\n";
    std::queue<TreeNode*> internalQ;
    internalQ.push(root);
    while(!internalQ.empty()) {
        TreeNode* curr = internalQ.front();
        internalQ.pop();

        std::cout << curr->value << " ";
        if(curr->left != nullptr) internalQ.push(curr->left);
        if(curr->right != nullptr) internalQ.push(curr->right);
    }

    std::cout << std::endl << "Level order traversal ended!" << std::endl;
};

void InorderTraversal(TreeNode* root) {
    std::cout << "Inorder traversal started\n";
    inorderHelper(root);
    std::cout << std::endl << "Inorder traversal ended" << std::endl;
};

void inorderHelper(TreeNode* node) {
    if(node == nullptr) return;

    inorderHelper(node->left);
    std::cout << node->value << " ";
    inorderHelper(node->right);
};

void PreOrderTraversal(TreeNode* root) {
    std::cout << "Preorder traversal started\n";
    preorderHelper(root);
    std::cout << std::endl << "Preorder traversal ended" << std::endl;
};

void preorderHelper(TreeNode* node) {
    if(node == nullptr) return;
    std::cout << node->value << " ";
    preorderHelper(node->left);
    preorderHelper(node->right);
};

void PostOrderTraversal(TreeNode* root) {
    std::cout << "Postorder traversal starting\n";
    postorderHelper(root);
    std::cout << std::endl <<"Postorder traversal ended" << std::endl;
};

void postorderHelper(TreeNode* node) {
    if(node == nullptr) return;

    postorderHelper(node->left);
    postorderHelper(node->right);
    std::cout << node->value << " ";
};

void MorrisTraversal(TreeNode* root) {
    std::cout << "Morris traversal started\n";
    TreeNode* curr = root;
    while(curr != nullptr) {
        if(curr->left == nullptr) {
            std::cout << curr->value << " ";
            curr = curr->right;
        } else {
            TreeNode* pred = morrisTraversalFindPredecessor(curr);
            if(pred->right == nullptr) {
                pred->right = curr;
                curr = curr->left;
            } else {
                pred->right = nullptr;
                std::cout << curr->value << " ";
                curr = curr->right;
            }
        }
    }
    std::cout << std::endl << "Morris traversal ended" << std::endl;
};

TreeNode* morrisTraversalFindPredecessor(TreeNode* node) {
    TreeNode* temp = node->left;
    while(temp->right != nullptr && temp->right != node) {
        temp = temp->right;
    }
    return temp;
}