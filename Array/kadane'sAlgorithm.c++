// Maximum subarray sum
/*Given an integer array nums, find the 
subarray
 with the largest sum, and return its sum.
Example 1:
Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.*/
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
// using kadane's algorithm

int maxSubarraySum(vector<int> &nums){
int currsum=0; int maxsum=INT_MIN;
for(int i=0; i<nums.size(); i++){
    currsum+=nums[i];
    maxsum=max(currsum, maxsum);
    if(currsum<0){
        currsum=0;
    }
}
return maxsum;

}
// Can be solved using DP array also 
int MaxSumSubarray(vector<int>&nums){
    vector<int>dp(nums.size());
    dp[0]=nums[0];
    int maxsum=dp[0];
    for(int i=1; i< nums.size(); i++){
        dp[i]=max(dp[i-1]+nums[i],nums[i]);
        maxsum=max(dp[i],maxsum);
    }
    return maxsum;
}



int main() {
ios::sync_with_stdio(0);
return 0;
}