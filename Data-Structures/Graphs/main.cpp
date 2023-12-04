#include <iostream>
#include "Graphs.hpp"

int main()
{
    Graphs<int> gph;
    gph.addEdge(1, 2);
    gph.addEdge(5, 6);
    gph.addEdge(3, 4);
    gph.printAdjacencyList();
    return 0;
}