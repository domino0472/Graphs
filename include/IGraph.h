#pragma once 

#include <vector>


struct Edge {
    int target;
    int weight;

   
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};


class IGraph {
public:
   
    virtual ~IGraph() = default; 

    virtual void addEdge(int u, int v, int weight) = 0;
    virtual std::vector<Edge> getOutgoingEdges(int vertex) const = 0;
    virtual int getVerticesCount() const = 0;
};