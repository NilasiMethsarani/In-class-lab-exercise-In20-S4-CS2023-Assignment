#include <iostream>
#include <list>
#include <unordered_set>
using namespace std;

struct Node {
    // A node will 2 entities
    //1. data type int called label
    //2. a int type list called neighbours
    int label;
    list<int> neighbours;// List to store the neighbours of the node
};

struct Graph {
    //graph will have an array of type "node" with length specified by n
    int n = 8;
    Node* nodes = new Node[n];
    //iterate through the nodes and assign labels
    void initializeNodes() {
        for (int i = 0; i < n; i++) {
            nodes[i].label = i + 1;
        }
    }

    void addEdge(int u, int v) {
        nodes[u - 1].neighbours.push_back(v);
        nodes[v - 1].neighbours.push_back(u);
    }

    void print() {
        for (int i = 0; i < n; i++) {
            cout << nodes[i].label << " --> ";
            bool isFirst = true;
            unordered_set<int> printed;
            for (int neighbour : nodes[i].neighbours) {
                if (printed.find(neighbour) == printed.end()) {
                    if (!isFirst) {
                        cout << " --> ";
                    }
                    cout << neighbour;
                    isFirst = false;
                    printed.insert(neighbour);
                }
            }
            cout << endl;
        }
    }
};

int main() {
    Graph* g = new Graph;
    g->initializeNodes();
    //add edges for the graphs here.
    g->addEdge(1, 2);
    g->addEdge(1, 3);
    g->addEdge(1, 4);
    g->addEdge(1, 5);
    g->addEdge(2, 6);
    g->addEdge(3, 2);
    g->addEdge(4, 6);
    g->addEdge(5, 6);
    g->addEdge(7, 4);
    g->addEdge(7, 5);
    g->addEdge(8, 4);
    g->addEdge(8, 5);
    //print the graph adjaceny list
    g->print();

    delete g;// To deallocate the memory
    return 0;
}

