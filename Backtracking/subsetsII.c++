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
void backtrack(int start, vector<int> &nums, vector<vector<int>> &result, vector<int> &current ){
    result.push_back(current);
    for(int i=start; i<nums.size(); i++){
        if(i>start && nums[i]==nums[i-1]){
            continue;
        }
        // choose nums[i]
        current.push_back(nums[i]);
        // recurse
        backtrack(i+1, nums, result, current);
        // undo the choice 
        current.pop_back();
    }
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
       sort(nums.begin(), nums.end()); // important for handling duplicates
    vector<vector<int>> result;
    vector<int> current;
    backtrack( 0,nums,result, current);
    return result;
       
        
    }
};