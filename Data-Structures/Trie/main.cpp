#include <iostream>
#include "Trie.hpp"

int main() {
    Trie t;
    t.insertWord("hello");
    std::cout << "Does `hello` exist in trie? " << t.searchWord("hello") << std::endl;
    return 0;
}