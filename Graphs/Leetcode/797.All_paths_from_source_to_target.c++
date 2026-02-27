//https://leetcode.com/problems/all-paths-from-source-to-target/?envType=problem-list-v2&envId=backtracking
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
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
      vector<vector<int>> res;
      queue<vector<int>> q;
      q.push({0});
      // perform bfs 
      while(!q.empty()){
        vector<int> path=q.front(); 
        q.pop();
        int lastnode= path.back();
        // check if the popped element is our goal node or not 
        if(lastnode==graph.size()-1){
            res.push_back(path);
            //continue;
        }
        // if it is not our goal node traverse the neigbhours
        // explore the rest of the neighbours as it is bfs so we need to check for the neighbours parallely
        for(int neighbour: graph[lastnode]){
            // copy the current path to traverse in diff direction
            vector<int> newpath =path;
            // add neighbour to the path 
            newpath.push_back(neighbour);
            q.push(newpath);
        }
      }  
      return res;
    }
};



int main() {
ios::sync_with_stdio(0);
return 0;
}