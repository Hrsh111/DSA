// https://leetcode.com/problems/permutations/
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
// helper function to calculate the factorial
        int factorial(int n){
            if(n==0 || n==1){
                return 1;
            }
             return n * factorial(n-1);
            
        }
    // Helper function to perform backtracking
    void backtrack(vector<int>& nums, vector<vector<int>>& res, int start) {
        // If we reach the end, add the current permutation to the result
        if (start == nums.size()) {
            res.push_back(nums);
            return;
        }

        for (int i = start; i < nums.size(); i++) {
            // Swap the current element with the element at the starting index
            swap(nums[start], nums[i]);
            
            // Recurse for the next index
            backtrack(nums, res, start + 1);

            // Backtrack: undo the swap
            swap(nums[start], nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        backtrack(nums, res, 0); // Start backtracking from index 0
        return res;
    }
};



int main() {
ios::sync_with_stdio(0);
return 0;
}

