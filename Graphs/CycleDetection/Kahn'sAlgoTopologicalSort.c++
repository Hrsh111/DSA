//Cycle Detection in a Directed Graph (Kahn's Algorithm - Topological Sort)
#include <bits/stdc++.h>
#include <queue>
#include <iostream>
using namespace std;

bool hasCycleDirectedKahn(int n, vector<vector<int>> &adj) {
    vector<int> indegree(n + 1, 0);

    // Calculate in-degree of each node
    for (int i = 1; i <= n; i++) {
        for (int neighbor : adj[i]) {
            indegree[neighbor]++;
        }
    }

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    int count = 0;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        count++;

        for (int neighbor : adj[node]) {
            indegree[neighbor]--;
            if (indegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    // If count of processed nodes != total nodes, there's a cycle
    return count != n;
}

int main() {
    int n = 4; // Number of nodes
    vector<vector<int>> adj(n + 1);
    adj[1] = {2};
    adj[2] = {3};
    adj[3] = {4};
    adj[4] = {2}; // Back edge creating a cycle

    if (hasCycleDirectedKahn(n, adj)) {
        cout << "Cycle detected in the directed graph (Kahn's Algorithm).\n";
    } else {
        cout << "No cycle in the directed graph (Kahn's Algorithm).\n";
    }

    return 0;
}
