#pragma once

#include "IGraph.h"
#include <vector>
#include <utility>


void generateRandomConnectedGraph(IGraph& graph, int E);





std::vector<int> findShortestPathBFS(const IGraph& graph, int start, int end);


std::vector<int> traverseDFS(const IGraph& graph, int start);


struct MSTResult {
    int totalWeight;
    std::vector<std::pair<int, int>> edges; 
};


MSTResult findMST_Prim(const IGraph& graph);