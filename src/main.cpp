#include <iostream>
#include <chrono> 
#include "Graphs.h"
#include "Algorithms.h"

using namespace std;
using namespace std::chrono; 


void runBenchmark(int V, int E) {
    cout << "=========================================\n";
    cout << "  BENCHMARK: V = " << V << ", E = " << E << "\n";
    cout << "=========================================\n";

    AdjacencyMatrixGraph matrixGraph(V);
    AdjacencyListGraph listGraph(V);

    cout << "1. Generowanie grafow (moze chwile potrwac)...\n";
    generateRandomConnectedGraph(listGraph, E);
    
    
    
    for (int i = 0; i < V; ++i) {
        for (const auto& edge : listGraph.getOutgoingEdges(i)) {
            matrixGraph.addEdge(i, edge.target, edge.weight);
        }
    }
    cout << "Gotowe!\n\n";

    
    cout << "--- MACIERZ SASIEDZTWA ---\n";
    auto startMatrix = high_resolution_clock::now();
    
    findMST_Prim(matrixGraph); 
    
    auto stopMatrix = high_resolution_clock::now();
    auto durationMatrix = duration_cast<milliseconds>(stopMatrix - startMatrix);
    cout << "Czas dzialania algorytmu Prima: " << durationMatrix.count() << " ms\n\n";

    
    cout << "--- LISTA SASIEDZTWA ---\n";
    auto startList = high_resolution_clock::now();
    
    findMST_Prim(listGraph); 
    
    auto stopList = high_resolution_clock::now();
    auto durationList = duration_cast<milliseconds>(stopList - startList);
    cout << "Czas dzialania algorytmu Prima: " << durationList.count() << " ms\n";
    cout << "=========================================\n\n";
}

int main() {
    
    int smallV = 6, smallE = 9;
    AdjacencyListGraph smallGraph(smallV);
    
    cout << "--- TEST POPRAWNOSCI (Maly graf) ---\n";
    generateRandomConnectedGraph(smallGraph, smallE);
    cout << "BFS z 0 do " << smallV - 1 << " - trasa: ";
    for (int v : findShortestPathBFS(smallGraph, 0, smallV - 1)) cout << v << " ";
    cout << "\nKolejnosc DFS: ";
    for (int v : traverseDFS(smallGraph, 0)) cout << v << " ";
    cout << "\nWaga MST: " << findMST_Prim(smallGraph).totalWeight << "\n\n";

   
    runBenchmark(2000, 5000); 
    
    
    runBenchmark(2000, 50000);

    
    
    return 0;
}