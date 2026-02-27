/*Given an integer array nums, return true if you can partition the array into two subsets such that the
 sum of the elements \in both subsets is equal or false otherwise.
Example 1:
Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].
Example 2:
Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.*/

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
   bool canPartition(vector<int>& nums) {
        int totalsum = 0;
       for(int num:nums) totalsum+= num;
        if(totalsum%2!=0) return false;
        int target=totalsum/2;
        vector<bool>dp(target+1, false);
        dp[0]=true;
        for(int num : nums){
            for(int j=target; j>=num;j--){// idk why the fck we are iterating from last 
                dp[j]= dp[j]||dp[j-num];
            }
        }
        return dp[target];
   }
};//creating a dp array of boolean values
// now we have to check whether we can form that number like dp[0,1,2,3...] from the given array by taking
//the subset from the original array 



int main() {
ios::sync_with_stdio(0);
return 0;
}