#include <vector>
using namespace std;

const int N = 100; // Adjust size
int adjMatrix[N][N] = {0};

void addEdge(int u, int v) {
    adjMatrix[u][v] = 1;
    adjMatrix[v][u] = 1; // Remove this for directed graphs
}
