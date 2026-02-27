#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);  // -1 = uncolored, 0 = color A, 1 = color B

        // we check all components (disconnected graph)
        for (int start = 0; start < n; start++) {
            if (color[start] != -1) continue;  // already visited

            queue<int> q;
            q.push(start);
            color[start] = 0;  // start with color 0

            while (!q.empty()) {
                int node = q.front();
                q.pop();

                for (int neighbor : graph[node]) {
                    if (color[neighbor] == -1) {
                        // color the neighbor with opposite color
                        color[neighbor] = 1 - color[node];
                        q.push(neighbor);
                    } else if (color[neighbor] == color[node]) {
                        // same color neighbor found — not bipartite
                        return false;
                    }
                }
            }
        }
        return true; // no conflict found, graph is bipartite
    }
};

int main() {
    Solution sol;
    vector<vector<int>> graph = {
        {1, 3},
        {0, 2},
        {1, 3},
        {0, 2}
    };

    if (sol.isBipartite(graph)) {
        cout << "Graph is Bipartite\n";
    } else {
        cout << "Graph is NOT Bipartite\n";
    }

    return 0;
}
