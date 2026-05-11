#include "Graphs.h"
#include <algorithm>

using namespace std;



AdjacencyMatrixGraph::AdjacencyMatrixGraph(int vertices) : numVertices(vertices) {
   
    matrix.assign(vertices, vector<int>(vertices, NO_EDGE));
}

void AdjacencyMatrixGraph::addEdge(int u, int v, int weight) {
    if (u >= 0 && u < numVertices && v >= 0 && v < numVertices) {
        matrix[u][v] = weight;
    }
}

vector<Edge> AdjacencyMatrixGraph::getOutgoingEdges(int vertex) const {
    vector<Edge> edges;
    if (vertex < 0 || vertex >= numVertices) return edges;

    for (int i = 0; i < numVertices; ++i) {
        if (matrix[vertex][i] != NO_EDGE) {
            edges.push_back({i, matrix[vertex][i]});
        }
    }
    
    
    sort(edges.begin(), edges.end());
    return edges;
}

int AdjacencyMatrixGraph::getVerticesCount() const {
    return numVertices;
}




AdjacencyListGraph::AdjacencyListGraph(int vertices) : numVertices(vertices) {
    adjList.resize(vertices);
}

void AdjacencyListGraph::addEdge(int u, int v, int weight) {
    if (u >= 0 && u < numVertices && v >= 0 && v < numVertices) {
        adjList[u].push_back({v, weight});
    }
}

vector<Edge> AdjacencyListGraph::getOutgoingEdges(int vertex) const {
    vector<Edge> edges;
    if (vertex < 0 || vertex >= numVertices) return edges;

    edges = adjList[vertex];
    
    
    sort(edges.begin(), edges.end());
    return edges;
}

int AdjacencyListGraph::getVerticesCount() const {
    return numVertices;
}