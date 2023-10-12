#ifndef TRIE_HPP
#define TRIE_HPP
#include <vector>
#include <string>
class Trie {
    private:
        struct Node
        {
            std::vector<Node*> alphabets;
            bool isEndOfWord;
            Node();
            ~Node();
        };
    
    public:
        Node* root;
        Trie();
        ~Trie();
        void insertWord(std::string);
        void deleteWord(std::string);
        bool searchWord(std::string);
};

#endif