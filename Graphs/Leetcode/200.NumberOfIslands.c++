// https://leetcode.com/problems/number-of-islands/
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

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        vector<pair<int,int>> directions={{1,0},{-1,0},{0,1},{0,-1}};
        int r=grid.size(),output=0;
        int c=grid[0].size();
        // bfs
        queue<pair<int,int >> q;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]=='1'){
                    output++;
                    grid[i][j]='0';
                    q.push({i,j});
                }
                while(!q.empty()){
                    auto[x,y]=q.front();
                    q.pop();
                    for(auto dir:directions){
                        int nx=x+dir.first;
                        int ny=y+dir.second;
                        if(nx>=0 && nx<r&& ny>=0 && ny<c && grid[nx][ny]=='1'){
                            grid[nx][ny]='0';
                            q.push({nx,ny});
                        }
                    }
                }
                
                
            }
        }
        return output;
        
    }
};


int main() {
ios::sync_with_stdio(0);
return 0;
}