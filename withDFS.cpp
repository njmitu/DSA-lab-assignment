
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class Graph {
private:
    int nodes;
    vector<vector<int>> adjMatrix;
    vector<bool> visited;

public:
    Graph(int n) {
        nodes = n;
        adjMatrix.resize(nodes, vector<int>(nodes, 0));
        visited.resize(nodes, false);
    }


    void addEdge(int u, int v) {
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
    }


    void dfs(int vertex) {
        visited[vertex] = true;
        cout << vertex << " ";


        for (int i = 0; i < nodes; i++) {
            if (adjMatrix[vertex][i] == 1 && !visited[i]) {
                dfs(i);
            }
        }
    }


    void resetVisited() {
        fill(visited.begin(), visited.end(), false);
    }
};

int main() {
    int nodes, edges;

    cout << "Enter the total number of nodes: ";
    cin >> nodes;
    cout << "Enter the total number of edges: ";
    cin >> edges;

    Graph g(nodes);

    cout << "Enter the edges (u v): " << endl;
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    int startNode;
    cout << "Enter the start node for DFS: ";
    cin >> startNode;

    cout << "DFS Traversal: ";
    g.dfs(startNode);
    cout << endl;

    return 0;
}
