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
void dfs(int node, vector<vector<int>>&isConnected, vector<int>visited){
    visited[node]=true;
    for (int i = 0; i < isConnected.size(); i++)
    {
        if(isConnected[node][i]==true && !visited[i]){
            dfs(i,isConnected, visited);
        }
    }
    
}
 int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int provinces=0;
        vector<int> visited(n, false);
        for (int i = 0; i < n; i++)
        {
            if(!visited[i]){
                 dfs(i, isConnected, visited);
            // each dfs marks a province
            provinces++;
            }
           
        }
         return provinces;
        
    }



int main() {
ios::sync_with_stdio(0);
return 0;
};