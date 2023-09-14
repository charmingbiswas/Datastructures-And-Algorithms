#include <iostream>
#include "DoublyLinkedList.h"

int main() {

    DoublyLinkedList l1;

    l1.appendNode(1);
    l1.appendNode(3);
    l1.appendNode(2);
    l1.appendNode(5);

    l1.printList();

    return 0;
}