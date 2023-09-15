#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

class DoublyLinkedList {
    private:
        struct Node {
            public:
                int data;
                DoublyLinkedList::Node* next;
                DoublyLinkedList::Node* prev;
                Node(int);
                ~Node();
        };
        DoublyLinkedList::Node* head;
        DoublyLinkedList::Node* tail;
        
    public:
        int lengthOfList;

        DoublyLinkedList();
        DoublyLinkedList(int);
        ~DoublyLinkedList();

        void appendNode(int);
        void deleteNode(int);
        void printList(void);
};

#endif