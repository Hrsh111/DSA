//Cycle Detection in a Directed Graph (DFS Approach)
#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, vector<vector<int>> &adj, vector<bool> &visited, vector<bool> &recStack) {
    visited[node] = true;
    recStack[node] = true;

    for (int neighbor : adj[node]) {
        if (!visited[neighbor] && dfs(neighbor, adj, visited, recStack)) {
            return true;
        } else if (recStack[neighbor]) {
            return true; // A back edge is found, indicating a cycle
        }
    }

    recStack[node] = false;
    return false;
}

bool hasCycleDirected(int n, vector<vector<int>> &adj) {
    vector<bool> visited(n + 1, false);
    vector<bool> recStack(n + 1, false);

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            if (dfs(i, adj, visited, recStack)) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    int n = 4; // Number of nodes
    vector<vector<int>> adj(n + 1);
    adj[1] = {2};
    adj[2] = {3};
    adj[3] = {4};
    adj[4] = {2}; // Back edge creating a cycle

    if (hasCycleDirected(n, adj)) {
        cout << "Cycle detected in the directed graph.\n";
    } else {
        cout << "No cycle in the directed graph.\n";
    }

    return 0;
}
