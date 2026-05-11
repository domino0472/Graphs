#pragma once

#include "IGraph.h"
#include <vector>
#include <limits>


class AdjacencyMatrixGraph : public IGraph {
private:
    int numVertices;
    std::vector<std::vector<int>> matrix;
    
    const int NO_EDGE = std::numeric_limits<int>::max(); 

public:
    
    AdjacencyMatrixGraph(int vertices);
    
    
    void addEdge(int u, int v, int weight) override;
    std::vector<Edge> getOutgoingEdges(int vertex) const override;
    int getVerticesCount() const override;
};



class AdjacencyListGraph : public IGraph {
private:
    int numVertices;
    std::vector<std::vector<Edge>> adjList;

public:
    
    AdjacencyListGraph(int vertices);
    
   
    void addEdge(int u, int v, int weight) override;
    std::vector<Edge> getOutgoingEdges(int vertex) const override;
    int getVerticesCount() const override;
};