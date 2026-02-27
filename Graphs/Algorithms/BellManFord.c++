#include <bits/stdc++.h>
#include <iostream>
#include <bits/stdc++.h>
#include <fstream>
#include <sstream>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include  <unordered_set>
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
using namespace std;

bool bellmanFord(int start, int n, vector<tuple<int, int, int>> &edges, vector<int> &dist) {
    dist[start] = 0;

    for (int i = 1; i < n; i++) {
        for (auto [u, v, w] : edges) {
            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    for (auto [u, v, w] : edges) {
        if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
            return false; // Negative weight cycle detected
        }
    }

    return true;
}

int main() {
    int n = 5; // Number of nodes
    vector<tuple<int, int, int>> edges = {
        {1, 2, 6}, {1, 3, 5}, {2, 4, -2}, {3, 2, -2}, {4, 5, 1}, {5, 1, -10}};

    vector<int> dist(n + 1, INT_MAX);
    if (bellmanFord(1, n, edges, dist)) {
        cout << "Shortest distances from node 1: ";
        for (int i = 1; i <= n; i++) {
            cout << dist[i] << " ";
        }
    } else {
        cout << "Negative weight cycle detected.";
    }
    return 0;
}
