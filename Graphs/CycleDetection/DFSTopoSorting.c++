#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void dfs(int node, vector<bool>& visited, stack<int>& topoStack, vector<vector<int> >& adj) {
    visited[node] = true;

    // Explore all neighbors of the current node
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, visited, topoStack, adj);
        }
    }

    // After all neighbors are processed, push the current node to the stack
    topoStack.push(node);
}

vector<int> topologicalSortDFS(int V, vector<vector<int> >& adj) {
    vector<bool> visited(V, false);
    stack<int> topoStack;

    // Perform DFS for all unvisited nodes
    for (int i = 0; i < V; ++i) {
        if (!visited[i]) {
            dfs(i, visited, topoStack, adj);
        }
    }

    // Retrieve the topological order by reversing the stack
    vector<int> topoOrder;
    while (!topoStack.empty()) {
        topoOrder.push_back(topoStack.top());
        topoStack.pop();
    }

    return topoOrder;
}

int main() {
    // Number of vertices
    int V = 6;

    // Adjacency list representation of the graph
    vector<vector<int>> adj(V);
    adj[5].push_back(0);
    adj[5].push_back(2);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);

    vector<int> result = topologicalSortDFS(V, adj);
    cout << "Topological Order: ";
    for (int v : result) {
        cout << v << " ";
    }

    return 0;
}
