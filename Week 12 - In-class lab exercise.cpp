#include <iostream>
#include <vector>
#include <limits>
using namespace std;

const int INF = numeric_limits<int>::max();

void printShortestPath(const vector<int>& parent, int node) {
    if (parent[node] == -1) {
        cout << node;
        return;
    }

    printShortestPath(parent, parent[node]);
    cout << " <- " << node;
}

void dijkstra(const vector<vector<int>>& weightMatrix, int numNodes, int source) {
    vector<int> distances(numNodes, INF); // Store shortest distances from the source node
    vector<bool> visited(numNodes, false); // Track visited nodes
    vector<int> parent(numNodes, -1); // Store parent nodes for constructing shortest paths

    distances[source] = 0;

    for (int i = 0; i < numNodes - 1; ++i) {
        int minDist = INF;
        int minIndex;

        // Find the node with the minimum distance
        for (int j = 0; j < numNodes; ++j) {
            if (!visited[j] && distances[j] <= minDist) {
                minDist = distances[j];
                minIndex = j;
            }
        }

        visited[minIndex] = true;

        // Update distances of adjacent nodes
        for (int j = 0; j < numNodes; ++j) {
            if (!visited[j] && weightMatrix[minIndex][j] && distances[minIndex] != INF &&
                distances[minIndex] + weightMatrix[minIndex][j] < distances[j]) {
                distances[j] = distances[minIndex] + weightMatrix[minIndex][j];
                parent[j] = minIndex;
            }
        }
    }

    // Printing the shortest paths and average time
    cout << "Shortest paths from node " << source << ":" << endl;
    double totalDistance = 0.0;

    for (int i = 0; i < numNodes; ++i) {
        if (i != source) {
            cout << "Distance from node " << source << " to " << i << " = " << distances[i] << endl;
            totalDistance += distances[i];

            cout << "Shortest path: ";
            printShortestPath(parent, i);
            cout << endl;
        }
    }

    double averageDistance = totalDistance / (numNodes - 1);
    cout << "Average distance of the shortest paths = " << averageDistance << endl;
}

int main() {
    int numNodes = 6;
    vector<vector<int>> weightMatrix = {
        {0, 10, 0, 0, 15, 5},
        {10, 0, 10, 30, 0, 0},
        {0, 10, 0, 12, 5, 0},
        {0, 30, 12, 0, 0, 20},
        {15, 0, 5, 0, 0, 0},
        {5, 0, 0, 20, 0, 0}
    };

    int sourceNode = 5; 

    dijkstra(weightMatrix, numNodes, sourceNode);

    return 0;
}
