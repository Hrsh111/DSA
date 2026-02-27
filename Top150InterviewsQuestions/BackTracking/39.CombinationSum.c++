//https://leetcode.com/problems/combination-sum/?envType=problem-list-v2&envId=backtracking
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
void backtrack(vector<int> &candidates, int target,int indx , vector<int> &path,vector<vector<int>>&res ){
    if(target ==0){// found the path equal to target 
        res.push_back(path);
        return;
    }
    if(target<0) return;
    for(int i =indx; i<candidates.size();i++){
        path.push_back(candidates[i]);
        backtrack(candidates,target-candidates[i],i,path,res);
        path.pop_back();
    }
    // explore all the candidates starting from indx
   
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> path;
        backtrack(candidates,target,0,path,res);
        return res;

    }
};

int main() {
ios::sync_with_stdio(0);
return 0;
}