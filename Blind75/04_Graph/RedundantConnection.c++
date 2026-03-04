/*
 * LeetCode #684 - Redundant Connection
 * https://leetcode.com/problems/redundant-connection/
 *
 * Given a list of edges forming a graph that started as a tree plus one extra
 * edge, return the redundant edge that makes a cycle.
 */

#include <bits/stdc++.h>
using namespace std;

// TODO: implement using DSU (union-find). Keep the test cases; implement the
// body of findRedundantConnection when practicing.
class Solution{
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges){
        return {};
    }
};

int main(){
    Solution sol;
    vector<vector<int>> e1 = {{1,2},{1,3},{2,3}};
    auto r1 = sol.findRedundantConnection(e1);
    cout<<"Test1:"; for(int x:r1) cout<<" "<<x; cout<<"\n"; // expected 2 3

    vector<vector<int>> e2 = {{1,2},{2,3},{3,4},{1,4},{1,5}};
    auto r2 = sol.findRedundantConnection(e2);
    cout<<"Test2:"; for(int x:r2) cout<<" "<<x; cout<<"\n"; // expected 1 4
    return 0;
}
