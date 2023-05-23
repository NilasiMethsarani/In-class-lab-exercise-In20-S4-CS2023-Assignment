#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Structure representing an edge between two vertices with its weight
struct Edge {
    int source, destination, weight;

    Edge(int src, int dest, int w) : source(src), destination(dest), weight(w) {}
};

// Function to add an edge to the graph
void addEdge(vector<vector<pair<int, int>>>& graph, int src, int dest, int weight) {
    graph[src].push_back(make_pair(dest, weight));
    graph[dest].push_back(make_pair(src, weight));
}

// Function to calculate the minimum spanning tree using Prim's algorithm
void primMST(const vector<vector<pair<int, int>>>& graph, int startNode) {
    int numVertices = graph.size();

    // Priority queue to store vertices with their key values
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Vector to store key values of vertices
    vector<int> key(numVertices, INT_MAX);

    // Vector to track the parent of each vertex in the MST
    vector<int> parent(numVertices, -1);

    // Vector to keep track of vertices included in MST
    vector<bool> inMST(numVertices, false);

    // Insert the start node into the priority queue
    pq.push(make_pair(0, startNode));
    key[startNode] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        // Mark the current vertex as visited
        inMST[u] = true;

        // Traverse all adjacent vertices of u
        for (auto& neighbor : graph[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            // If v is not in MST and the weight of the edge (u,v) is smaller than the current key of v
            if (!inMST[v] && weight < key[v]) {
                // Update the key value and parent of v
                key[v] = weight;
                parent[v] = u;
                pq.push(make_pair(key[v], v));
            }
        }
    }

    // Print the minimum spanning tree
    cout << "Minimum Spanning Tree:\n";
    for (int i = 0; i < numVertices; ++i) {
        if (parent[i] != -1)
            cout << parent[i] << " - " << i << " : " << key[i] << endl;
    }
}

int main() {
    vector<vector<pair<int, int>>> graph(6);

    // Add edges to the graph
    addEdge(graph, 0, 1, 3);
    addEdge(graph, 0, 5, 1);
    addEdge(graph, 1, 2, 2);
    addEdge(graph, 1, 3, 1);
    addEdge(graph, 1, 4, 10);
    addEdge(graph, 2, 3, 3);
    addEdge(graph, 2, 5, 5);
    addEdge(graph, 3, 4, 5);
    addEdge(graph, 4, 5, 4);

    int startNode;
    cout << "Enter the starting node: ";
    cin >> startNode;

    // Calculate and print the minimum spanning tree with the user-defined start node
    primMST(graph, startNode);
    return 0;
}
