#include "DoublyLinkedList.hpp"
#include <iostream>

DoublyLinkedList::DoublyLinkedList(int length) 
    : lengthOfList{length}, head{nullptr}, tail{nullptr}
{};

DoublyLinkedList::DoublyLinkedList()
    : DoublyLinkedList::DoublyLinkedList(0)
{};

DoublyLinkedList::~DoublyLinkedList() 
{
    //Clean up code, destroy all dynamically allocated memory created for nodes
    auto current = head;
    auto next = head->next;

    while(current) {
        delete current;
        current = next;
        next = current->next;
    }
};

DoublyLinkedList::Node::Node(int value)
    : data{value}
{};

DoublyLinkedList::Node::~Node() {
    std::cout << "Node with value " << Node::data << " deleted!" << std::endl;
};


void DoublyLinkedList::appendNode(int value) {
    DoublyLinkedList::Node* newNode = new DoublyLinkedList::Node(value);
    if(head == nullptr) {
        head = newNode;
        tail = newNode;
        lengthOfList++;
        return;
    }

    auto tempPointer = tail;

    while(tempPointer->next != nullptr) {
        tempPointer = tempPointer->next;
    }

    tempPointer->next = newNode;
    tail = newNode;
};

void DoublyLinkedList::deleteNode(int index) {
    //start with first index. Non-zero based indexing used.
    int i = 1;
    //createa a temporary node for list traversal
    auto tempNode = head;
    while(i < index) {
        tempNode = tempNode->next;
        i++;
    }

    //store previous and next nodes
    auto nextNode = tempNode->next;
    auto prevNode = tempNode->prev;
    //delete current node (tempNode in this case)
    delete tempNode;
    
    //next of previous node should point to nextNode
    prevNode->next = nextNode;
};