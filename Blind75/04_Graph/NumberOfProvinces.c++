/*
 * LeetCode #547 - Number of Provinces (Friend Circles)
 * https://leetcode.com/problems/number-of-provinces/
 * There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is
 *  connected directly with city c, then city a is connected indirectly with city c.
 * You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected,
 *  and isConnected[i][j] = 0 otherwise.
 * Return the total number of provinces.
 * A province is a group of directly or indirectly connected cities and no other cities outside of the group.


 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
        // DSU approach
        // Find function
        int find_parent(vector<int> &parent,int i){
            if(parent[i]==i){
                return i;
            }
           return find_parent(parent,parent[i]);
        }
        // union function
        void union_set(vector<int> &parent,int node1, int node2 ) {
            int root1=find_parent(parent,node1);
            int root2=find_parent(parent,node2);
            if(root1!=root2){
                parent[root2]=root1;// attaching the nodes to same set 
            }
        }


    int findCircleNum(vector<vector<int>>& isConnected) {
        int r= isConnected.size();
        int c= isConnected[0].size();
        int provinces=0;
       vector<int> parent(r);
       for(int i=0;i<r;i++){
        parent[i]=i;
       }
       for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(isConnected[i][j]==1){
                union_set(parent, i,j);
            }
        }
       }
       for(int i=0;i<r;++i){
        if(parent[i]==i){
            ++provinces;
        }
       }
       return provinces;
}
};

int main(){
    Solution sol;
    vector<vector<int>> m1 = {{1,1,0},{1,1,0},{0,0,1}};
    cout<<"Test1: "<<sol.findCircleNum(m1)<<"\n"; // Expected 2
    vector<vector<int>> m2 = {{1,0,0},{0,1,0},{0,0,1}};
    cout<<"Test2: "<<sol.findCircleNum(m2)<<"\n"; // Expected 3
    return 0;
}
