/*
 * LeetCode #785 - Is Graph Bipartite?
 * https://leetcode.com/problems/is-graph-bipartite/
 *
 * Given an undirected graph as adjacency list, determine if it's bipartite
 * (2-colorable) using BFS/DFS coloring.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TODO: implement BFS/DFS coloring; return true if bipartite
    bool isBipartite(vector<vector<int>>& graph) {
        return false;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> g1 = {{1,3},{0,2},{1,3},{0,2}}; // bipartite
    cout<<"Test1: "<<(sol.isBipartite(g1)?"true":"false")<<"\n"; // true
    vector<vector<int>> g2 = {{1,2,3},{0,2},{0,1,3},{0,2}}; // not bipartite
    cout<<"Test2: "<<(sol.isBipartite(g2)?"true":"false")<<"\n"; // false
    return 0;
}
