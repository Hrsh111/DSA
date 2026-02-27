#include <bits/stdc++.h>
#include <queue>
#include <iostream>
using namespace std;

void dijkstra(int start, vector<vector<pair<int, int>>> &adj, vector<int> &dist) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, start});
    dist[start] = 0;

    while (!pq.empty()) {
        auto [currentDist, node] = pq.top();
        pq.pop();

        if (currentDist > dist[node]) continue;

        for (auto [neighbor, weight] : adj[node]) {
            if (dist[node] + weight < dist[neighbor]) {
                dist[neighbor] = dist[node] + weight;
                pq.push({dist[neighbor], neighbor});
            }
        }
    }
}

int main() {
    int n = 5; // Number of nodes
    vector<vector<pair<int, int>>> adj(n + 1);
    adj[1] = {{2, 2}, {3, 4}};
    adj[2] = {{1, 2}, {4, 7}};
    adj[3] = {{1, 4}, {4, 1}};
    adj[4] = {{2, 7}, {3, 1}, {5, 3}};
    adj[5] = {{4, 3}};

    vector<int> dist(n + 1, INT_MAX);
    dijkstra(1, adj, dist);

    cout << "Shortest distances from node 1: ";
    for (int i = 1; i <= n; i++) {
        cout << dist[i] << " ";
    }
    return 0;
}
