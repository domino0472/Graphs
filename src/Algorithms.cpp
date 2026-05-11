#include "Algorithms.h"
#include <queue>
#include <stack>
#include <algorithm>
#include <limits>
#include <random>
#include <set>
#include <stdexcept>
#include <iostream> 

using namespace std;



void generateRandomConnectedGraph(IGraph& graph, int E) {
    int V = graph.getVerticesCount();
    
    if (E < V - 1) {
        throw invalid_argument("Graf spojny musi miec co najmniej V - 1 krawedzi.");
    }
    long long maxEdges = (long long)V * (V - 1) / 2;
    if (E > maxEdges) {
        throw invalid_argument("Zbyt duzo krawedzi dla grafu prostego.");
    }

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> weightDist(1, 100);

    set<pair<int, int>> existingEdges;

    auto addUndirectedEdge = [&](int u, int v, int w) {
        if (u > v) swap(u, v);
        existingEdges.insert({u, v});
        graph.addEdge(u, v, w);
        graph.addEdge(v, u, w);
    };

    vector<int> connectedVertices;
    connectedVertices.push_back(0);
    
    vector<int> unconnectedVertices;
    for (int i = 1; i < V; ++i) unconnectedVertices.push_back(i);
    
    shuffle(unconnectedVertices.begin(), unconnectedVertices.end(), gen);

    for (int v : unconnectedVertices) {
        uniform_int_distribution<> dist(0, connectedVertices.size() - 1);
        int u = connectedVertices[dist(gen)];
        int w = weightDist(gen);
        addUndirectedEdge(u, v, w);
        connectedVertices.push_back(v);
    }

    int remainingEdges = E - (V - 1);
    uniform_int_distribution<> vertexDist(0, V - 1);

    while (remainingEdges > 0) {
        int u = vertexDist(gen);
        int v = vertexDist(gen);

        if (u != v) {
            int first = min(u, v);
            int second = max(u, v);

            if (existingEdges.find({first, second}) == existingEdges.end()) {
                int w = weightDist(gen);
                addUndirectedEdge(first, second, w);
                remainingEdges--;
            }
        }
    }
}



vector<int> findShortestPathBFS(const IGraph& graph, int start, int end) {
    int V = graph.getVerticesCount();
    vector<bool> visited(V, false);
    vector<int> parent(V, -1);
    queue<int> q;

    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        if (current == end) break;

        for (const auto& edge : graph.getOutgoingEdges(current)) {
            if (!visited[edge.target]) {
                visited[edge.target] = true;
                parent[edge.target] = current;
                q.push(edge.target);
            }
        }
    }

    vector<int> path;
    if (!visited[end]) return path;

    for (int at = end; at != -1; at = parent[at]) {
        path.push_back(at);
    }
    reverse(path.begin(), path.end());
    
    return path;
}


static void dfsUtil(const IGraph& graph, int v, vector<bool>& visited, vector<int>& result) {
    visited[v] = true;
    result.push_back(v);

    for (const auto& edge : graph.getOutgoingEdges(v)) {
        if (!visited[edge.target]) {
            dfsUtil(graph, edge.target, visited, result);
        }
    }
}

vector<int> traverseDFS(const IGraph& graph, int start) {
    int V = graph.getVerticesCount();
    vector<bool> visited(V, false);
    vector<int> result;
    dfsUtil(graph, start, visited, result);
    return result;
}

MSTResult findMST_Prim(const IGraph& graph) {
    int V = graph.getVerticesCount();
    vector<bool> inMST(V, false);
    MSTResult result;
    result.totalWeight = 0;

    typedef pair<int, pair<int, int>> QueueItem;
    priority_queue<QueueItem, vector<QueueItem>, greater<QueueItem>> pq;

    inMST[0] = true;
    for (const auto& edge : graph.getOutgoingEdges(0)) {
        pq.push({edge.weight, {0, edge.target}});
    }

    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();

        int weight = top.first;
        int u = top.second.first;
        int v = top.second.second;

        if (inMST[v]) continue;

        inMST[v] = true;
        result.totalWeight += weight;
        result.edges.push_back({u, v});

        for (const auto& edge : graph.getOutgoingEdges(v)) {
            if (!inMST[edge.target]) {
                pq.push({edge.weight, {v, edge.target}});
            }
        }
    }

    return result;
}