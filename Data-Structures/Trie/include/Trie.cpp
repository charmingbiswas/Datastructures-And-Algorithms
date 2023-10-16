#include <iostream>
#include <stack>
#include "Trie.hpp"

// constructor for internal Node struct
Trie::Node::Node() : alphabets{26, nullptr}, isEndOfWord{false} {
    std::cout << "New node created\n";
};

// destructor for internal Node struct
Trie::Node::~Node() {
    std::cout << "Node destroyed\n";
};

// constructor for Trie data structure
Trie::Trie() : root{new Node()} {};

// destructor for Trie data structure
Trie::~Trie() {
    recursiveDeleteNodePrivate(root);
    std::cout << "Trie destroyed, memory freed\n";
};

void Trie::recursiveDeleteNodePrivate(Node* node) {
    if(node->isEndOfWord == true) {
        delete node;
        return;
    }

    for(auto n : node->alphabets) {
        if(n != nullptr) {
            recursiveDeleteNodePrivate(n);
        } else continue;
    }

    delete node;
}

void Trie::insertWord(std::string word) {
    auto current = root;
    for(auto s : word) {
        if(current->alphabets[s - 'a'] == nullptr) {
            current->alphabets[s - 'a'] = new Node();
            current = current->alphabets[s - 'a'];
        } else {
            current = current->alphabets[s - 'a'];
        }
    }
    current->isEndOfWord = true;
    std::cout << "Inserted word `" << word << "` into trie." << std::endl;
};

// void Trie::deleteWord(std::string word) {
    
// }


bool Trie::searchWord(std::string word) {
    auto current = root;
    for(auto s : word) {
        if(current->alphabets[s - 'a'] == nullptr) return false;
        else current = current->alphabets[s - 'a'];
    }

    if(current->isEndOfWord == true) return true;
    else return false;
};