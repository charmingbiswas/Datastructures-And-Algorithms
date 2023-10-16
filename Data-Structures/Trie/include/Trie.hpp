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
        void recursiveDeleteNodePrivate(Node*); // To delete all dynamic Nodes in the Trie when the destructor is called
    
    public:
        Node* root;
        Trie();
        ~Trie();
        void insertWord(std::string);
        void deleteWord(std::string);
        bool searchWord(std::string);
};

#endif