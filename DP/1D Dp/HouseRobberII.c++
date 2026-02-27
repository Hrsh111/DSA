#include <bits/stdc++.h>
#include <iostream>

using namespace std;
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

int robHelper(vector<int> &nums){
    // for the circle formed by the arrays nums[0] & nums[n] cannot be robbed at the same time
    int n = nums.size();
    if(n==0) return 0;
    if(n==1) return nums[0];
      vector<int> dp(n+1, -1);
      dp[0]=nums[0];
      dp[1]= max(nums[0], nums[1]);
      for(int i = 2; i<n; i++){
        dp[i]= max(dp[i-1], dp[i-2]+nums[i]);
      }
      return dp[n-1];


      }
      int rob(vector<int> &nums){
        int n = nums.size();
        if(n<2){
            return nums[0];
        }
        // creating two new arrays for the taken and not taken cases and fill them 
        // skipping the first element 
        vector<int> SkipFirst(nums.begin()+1, nums.end());// here it is a range constructor which copies
        // the array nums from the required index 
            int SkippingFirst= robHelper(SkipFirst);
            // skipping the last element 
            vector<int> SkipLast(nums.begin(), nums.end());
            int SkippingLast= robHelper(SkipLast);
            return max(SkippingFirst, SkippingLast);

      }





int main() {
ios::sync_with_stdio(0);
cin.tie(0);
vector<int> nums= {2,7,3,1,4,2,1,8};
cout << "Maximum loot: " << rob(nums) << endl;
return 0;
}