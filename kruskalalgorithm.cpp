#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class DSU {
private:
    vector<int> parent, size;

public:

    DSU(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
    }


    int find(int v) {
        if (v == parent[v])
            return v;
        return parent[v] = find(parent[v]);
    }


    void Union(int a, int b) {
        int rootA = find(a);
        int rootB = find(b);

        if (rootA != rootB) {
            
            if (size[rootA] < size[rootB]) {
                swap(rootA, rootB);
            }
            parent[rootB] = rootA;  
            size[rootA] += size[rootB];  
        }
    }
};


class KruskalMST {
private:
    vector<pair<int, pair<int, int>>> edges;  

public:
    
    void addEdge(int u, int v, int weight) {
        edges.push_back({weight, {u, v}});
    }

    
    int findMST(int nodes) {
        
        sort(edges.begin(), edges.end());

        DSU dsu(nodes);
        int totalCost = 0;

        cout << "(u, v) -> weight" << endl;

        for (auto &edge : edges) {
            int weight = edge.first;
            int u = edge.second.first;
            int v = edge.second.second;


            if (dsu.find(u) != dsu.find(v)) {
                dsu.Union(u, v);
                totalCost += weight;
                cout << u << " " << v << " -> " << weight << endl;
            }
        }

        return totalCost;
    }
};

int main() {
    int nodes, edges;
    cout << "number of nodes and edges: ";
    cin >> nodes >> edges;

    KruskalMST kruskal;

    cout << "Enter edges (u, v, weight):" << endl;
    for (int i = 0; i < edges; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        kruskal.addEdge(u, v, weight);
    }


    int totalCost = kruskal.findMST(nodes);

    cout << "Minimum cost of the MST: " << totalCost << endl;

    return 0;
}
