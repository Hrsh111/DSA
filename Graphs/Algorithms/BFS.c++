#include <vector>
#include <queue>
#include <iostream>
using namespace std;
 void BFS(int Startnode, vector<vector<int>>& adj, vector<bool>& visited) {
        queue<int> q;
        q.push(Startnode);
        visited[Startnode] = true;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            for (int j = 0; j < adj.size(); j++) {
                if (adj[curr][j] == 1 && !visited[j]) {
                    q.push(j);
                    visited[j] = true;
                }
            }
        }
    }

const int N = 1e5;
vector<int> adj[N];
vector<bool> visited(N, false);

void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " "; // Process node

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}
