// Cycle Detection in an Undirected Graph (Union-Find)
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int findParent(int node, vector<int> &parent) {
    if (parent[node] == -1) return node;
    return parent[node] = findParent(parent[node], parent); // Path compression
}

bool unionNodes(int u, int v, vector<int> &parent) {
    int parentU = findParent(u, parent);
    int parentV = findParent(v, parent);

    if (parentU == parentV) {
        return true; // Cycle detected
    }

    parent[parentU] = parentV; // Union
    return false;
}

bool hasCycleUndirectedUnionFind(int n, vector<pair<int, int>> &edges) {
    vector<int> parent(n + 1, -1);

    for (auto [u, v] : edges) {
        if (unionNodes(u, v, parent)) {
            return true;
        }
    }

    return false;
}

int main() {
    int n = 5; // Number of nodes
    vector<pair<int, int>> edges = {{1, 2}, {2, 3}, {3, 4}, {4, 5}, {3, 1}}; // Cycle exists

    if (hasCycleUndirectedUnionFind(n, edges)) {
        cout << "Cycle detected in the undirected graph (Union-Find).\n";
    } else {
        cout << "No cycle in the undirected graph (Union-Find).\n";
    }

    return 0;
}
