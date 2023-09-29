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
    if(head == nullptr) return;

    auto current = head;
    auto next = head->next;

    while(current != nullptr) {
        delete current;
        current = next;
        if(next != nullptr)
            next = next->next;
    }
};

DoublyLinkedList::Node::Node(int value)
    : data{value}, next{nullptr}, prev{nullptr}
{};

DoublyLinkedList::Node::~Node() {
    std::cout << "Node with value " << Node::data << " deleted!" << std::endl;
};


void DoublyLinkedList::appendNode(int value) {
    Node* newNode = new Node(value);
    // if list is empty
    if(head == nullptr) {
        head = newNode;
        tail = newNode;
    }
    else {
        auto temp = tail;
        tail->next = newNode;
        newNode->prev = temp;
        tail = newNode;
    }
}

void DoublyLinkedList::deleteNode() {
    if(head == nullptr) return;
    else {
        auto temp = tail->prev;
        delete tail;
        tail = temp;
        tail->next = nullptr;
    }
}

void DoublyLinkedList::printList() {
    if(head == nullptr) return;

    auto temp = head;
    while(temp != nullptr) {
        std::cout << temp->data << std::endl;
        temp = temp->next;
    }
}