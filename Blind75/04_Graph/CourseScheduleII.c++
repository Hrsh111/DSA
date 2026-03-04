/*
 * LeetCode #210 - Course Schedule II
 * https://leetcode.com/problems/course-schedule-ii/
 *
 * Return a possible ordering of courses given prerequisites or empty if cycle.
 * Uses Kahn's algorithm (BFS topological sort).
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TODO: implement Kahn's algorithm or DFS-based topo and return order
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites){
        return {};
    }
};

int main(){
    Solution sol;
    vector<vector<int>> p1 = {{1,0}};
    auto r1 = sol.findOrder(2,p1);
    cout<<"Test1:"; for(int x:r1) cout<<" "<<x; cout<<"\n"; // 0 1

    vector<vector<int>> p2 = {{1,0},{2,0},{3,1},{3,2}};
    auto r2 = sol.findOrder(4,p2);
    cout<<"Test2:"; for(int x:r2) cout<<" "<<x; cout<<"\n"; // 0 1 2 3 or 0 2 1 3

    vector<vector<int>> p3 = {{1,0},{0,1}};
    auto r3 = sol.findOrder(2,p3);
    cout<<"Test3:"<<(r3.empty()?string("empty"):"? non-empty")<<"\n"; // empty
    return 0;
}
