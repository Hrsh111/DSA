#include <bits/stdc++.h>
#include <fstream>
#include <sstream>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <deque>
#include <algorithm>
#include <iterator>
#include <cmath>
#include <complex>
#include <utility>
#include <limits>
#include <string>
#include <type_traits>
#include <chrono>
using namespace std;
#include <iostream>
#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define pb push_back
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define rep(i, a, b) for (int i = a; i < b; ++i)

// Disjoint Set / Union-Find data structure
class DisjointSet {
public:
    vector<int> parent, rank;
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        iota(parent.begin(), parent.end(), 0); // Initialize parent as its own node
    }

    int find(int u) {
        if (parent[u] != u) {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }

    void unite(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);

        if (rootU != rootV) {
            if (rank[rootU] < rank[rootV]) {
                parent[rootU] = rootV;
            } else if (rank[rootU] > rank[rootV]) {
                parent[rootV] = rootU;
            } else {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
        }
    }
};

// Edge data structure
struct Edge {
    int u, v, w;
    bool operator<(Edge const &other) { return w < other.w; }
};

vector<Edge> kruskalMST(int n, vector<Edge> &edges) {
    sort(edges.begin(), edges.end()); // Sort edges based on weight
    DisjointSet ds(n);
    vector<Edge> mst;

    for (auto &edge : edges) {
        int u = edge.u, v = edge.v, w = edge.w;
        if (ds.find(u) != ds.find(v)) {
            ds.unite(u, v);
            mst.push_back(edge);
        }
    }

    return mst;
}

int main() {
    int n = 6; // Number of nodes
    vector<Edge> edges = {
        {0, 1, 4}, {0, 2, 3}, {0, 3, 2},
        {1, 2, 1}, {1, 4, 5}, {2, 3, 4},
        {2, 5, 6}, {3, 5, 2}, {4, 5, 3}
    };

    vector<Edge> mst = kruskalMST(n, edges);

    int totalWeight = 0;
    for (auto &edge : mst) {
        cout << "Edge: " << edge.u << " - " << edge.v << " Weight: " << edge.w << endl;
        totalWeight += edge.w;
    }

    cout << "Total Weight of MST: " << totalWeight << endl;

    return 0;
}
