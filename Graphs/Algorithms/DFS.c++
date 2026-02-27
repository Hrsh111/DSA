#include <vector>
#include <iostream>
#include <stack>
using namespace std;
// Recursive DFS uses a call stack of the system and  not any explicit stack 
void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited) {
    // Mark the current node as visited
    visited[node] = true;

    // Explore all neighbors
    for (int j = 0; j < adj.size(); j++) {
        if (adj[node][j] == 1 && !visited[j]) {
            // If there's a connection and the node  is not visited, recurse
            dfs(j, adj, visited);
        }
    }
}
// Iterative dfs uses a stack 
void iterativeDFS(int startNode, vector<vector<int>>& adj, vector<bool>& visited) {
    stack<int> s;
    s.push(startNode);
    visited[startNode] = true;

    while (!s.empty()) {
        int curr = s.top();
        s.pop();

        for (int j = 0; j < adj.size(); j++) {
            if (adj[curr][j] == 1 && !visited[j]) {
                s.push(j);
                visited[j] = true;
            }
        }
    }
}
