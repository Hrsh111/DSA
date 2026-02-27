//Cycle Detection in an Undirected Graph (DFS Approach)

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

bool dfs(int node, int parent, vector<vector<int>> &adj, vector<bool> &visited) {
    visited[node] = true;

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            if (dfs(neighbor, node, adj, visited)) {
                return true;
            }
        } else if (neighbor != parent) {
            return true; // A back edge is found, indicating a cycle
        }
    }

    return false;
}

bool hasCycleUndirected(int n, vector<vector<int>> &adj) {
    vector<bool> visited(n + 1, false);

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, adj, visited)) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    int n = 5; // Number of nodes
    vector<vector<int>> adj(n + 1);
    adj[1] = {2, 3};
    adj[2] = {1, 4};
    adj[3] = {1, 5};
    adj[4] = {2};
    adj[5] = {3};

    if (hasCycleUndirected(n, adj)) {
        cout << "Cycle detected in the undirected graph.\n";
    } else {
        cout << "No cycle in the undirected graph.\n";
    }

    return 0;
}
