/*
 * Grid BFS example - shortest path in grid (4-directional) avoiding blocked cells
 * Simple demo for BFS on adjacency-matrix-style grid.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    // TODO: implement BFS for shortest path in grid avoiding blocked cells.
    int shortestPath(vector<vector<int>>& grid, pair<int,int> src, pair<int,int> dst){
        return -1;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> g1 = {
        {0,0,0},
        {1,1,0},
        {0,0,0}
    };
    cout<<"Test1: "<<sol.shortestPath(g1,{0,0},{2,2})<<"\n"; // Expected 4
    vector<vector<int>> g2 = {
        {0,1,0},
        {1,1,0},
        {0,0,0}
    };
    cout<<"Test2: "<<sol.shortestPath(g2,{0,0},{2,2})<<"\n"; // Expected -1 (blocked)
    return 0;
}
