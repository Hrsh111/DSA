//https://leetcode.com/problems/subsets/description/
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
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        backtrack(nums,0,path,res);
        return res;
    }
    void backtrack(vector<int>&nums, int start, vector<int> &path, vector<vector<int>>&res){
        res.push_back(path);
        for(int i=start;i<nums.size();i++){
            path.push_back(nums[i]);
            backtrack(nums,i+1,path,res);
            path.pop_back();
        }
    }
};

int main() {
ios::sync_with_stdio(0);
return 0;
}
