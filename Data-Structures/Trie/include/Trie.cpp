#include <iostream>
#include "Trie.hpp"

// constructor for internal Node struct
Trie::Node::Node() : alphabets{26, nullptr}, isEndOfWord{false} {};

// destructor for internal Node struct
Trie::Node::~Node() {
    std::cout << "Node destroyed\n";
};

// constructor for Trie data structure
Trie::Trie() : root{nullptr} {};

// destructor for Trie data structure
Trie::~Trie() {
    std::cout << "Trie destroyed, memory freed\n";
};

void Trie::insertWord(std::string word) {
    auto currentNode = root;
    for(char i : word) {
        
    }
};

void Trie::deleteWord(std::string word) {

};

bool Trie::searchWord(std::string word) {

};