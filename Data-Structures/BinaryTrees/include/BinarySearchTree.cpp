#include "BinarySearchTree.hpp"

#include <iostream>
#include <vector>

BinarySearchTree::BinarySearchTree(std::vector<int>& vec)
    : root{nullptr} {
        BinarySearchTree::createBinaryTreePrivate(vec);
    };
BinarySearchTree::~BinarySearchTree() {};

void BinarySearchTree::createBinaryTreePrivate(std::vector<int>& v) {
    
};
void BinarySearchTree::inOrderTraversal() {};
void BinarySearchTree::preOrderTraversal() {};
void BinarySearchTree::postOrderTraversal() {};