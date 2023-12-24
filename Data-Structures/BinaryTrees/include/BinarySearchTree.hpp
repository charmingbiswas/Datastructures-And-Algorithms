#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <vector>

class BinarySearchTree {
    private:
        struct Node
        {
            public:
                int value;
                Node* left;
                Node* right;

                Node(int);
                ~Node();
        };

        void createBinaryTreePrivate(std::vector<int>&);
    public:
        Node* root;
        void inOrderTraversal();
        void preOrderTraversal();
        void postOrderTraversal();

        BinarySearchTree(std::vector<int>&);
        ~BinarySearchTree();
};

#endif