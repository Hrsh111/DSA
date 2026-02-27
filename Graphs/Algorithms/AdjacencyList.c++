#include <vector>
using namespace std;

const int N = 1e5; // Adjust based on the problem
vector<int> adj[N]; // Adjacency list for an undirected graph

void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u); // Remove this for directed graphs
}
