#ifndef GRAPHS_H
#define GRAPHS_H

#include <unordered_map>
#include <list>

template <typename T>
class Graphs
{
private:
    bool isDirected;
    std::unordered_map<T, std::list<T>> adjacencyList;

public:
    Graphs() : Graphs::Graphs(false){};
    Graphs(bool value) : isDirected{value} {};
    ~Graphs() { std::cout << "Graphs destroyed, memory freed" << std::endl; };
    void addEdge(T v1, T v2)
    {
        adjacencyList[v1].push_back(v2);
        if (isDirected == false)
        {
            adjacencyList[v2].push_back(v1);
        }
    };
    void printAdjacencyList()
    {
        for (auto i : adjacencyList)
        {
            std::cout << i.first << "-> ";
            for (auto j : i.second)
            {
                std::cout << j << ", ";
            }
            std::cout << std::endl;
        }
    };
    void printBFS();
    void printDFS();
};
#endif