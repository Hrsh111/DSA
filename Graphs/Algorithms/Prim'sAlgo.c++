#include <bits/stdc++.h>
#include <queue>
#include <iostream>
using namespace std;

const int INF = 1e9;

vector<int> primMST(int n, vector<vector<pair<int, int>>> &adj) {
    vector<int> key(n, INF), parent(n, -1), mstSet(n, 0);
    key[0] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // Min-heap

    pq.push({0, 0});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        mstSet[u] = 1;

        for (auto &neighbor : adj[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            if (!mstSet[v] && weight < key[v]) {
                key[v] = weight;
                pq.push({key[v], v});
                parent[v] = u;
            }
        }
    }

    return parent;
}

int main() {
    int n = 5; // Number of nodes
    vector<vector<pair<int, int>>> adj(n);

    adj[0].push_back({1, 2});
    adj[0].push_back({3, 6});
    adj[1].push_back({0, 2});
    adj[1].push_back({2, 3});
    adj[1].push_back({3, 8});
    adj[2].push_back({1, 3});
    adj[2].push_back({4, 5});
    adj[3].push_back({0, 6});
    adj[3].push_back({1, 8});
    adj[4].push_back({2, 5});

    vector<int> mst = primMST(n, adj);

    cout << "Edges in MST:" << endl;
    for (int i = 1; i < n; i++) {
        cout << "Edge: " << mst[i] << " - " << i << " Weight: " << adj[i][0].second << endl;
    }

    return 0;
}
