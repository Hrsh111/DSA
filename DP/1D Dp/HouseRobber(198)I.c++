#include <iostream>  
#include <vector>    
#include <algorithm> 
#include <cmath>     
#include <cstring>   
#include <cstdio>    
#include <sstream>   
#include <map>       
#include <set>       
#include <stack>     
#include <queue>     
#include <deque>     
#include <list>      
#include <utility>   
#include <functional>
#include <iterator>  
#include <limits>    
#include <type_traits> 

using namespace std;  

    int rob(vector<int>& nums) {
        int n= nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];

        vector<int> dp(n+1, -1);
        dp[0]=nums[0];
        dp[1]= max(nums[0],nums[1]);
        for(int i=2; i<n; i++){
            dp[i]= max(dp[i-1], dp[i-2] +nums[i]);
        }
        return dp[n-1];
    };
// more optimized solution for this question without using the dp array instead using 2 more variables 

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        // Variables to store the previous two maximum sums
        int prev2 = 0;       // dp[i-2]
        int prev1 = nums[0]; // dp[i-1]

        for (int i = 1; i < n; i++) {
            int current = max(prev1, prev2 + nums[i]); // Current maximum sum
            prev2 = prev1;    // Update dp[i-2] to dp[i-1]
            prev1 = current;  // Update dp[i-1] to current
        }

        return prev1; // The maximum sum at the last house
    };



int main(){
    
    
    
    return 0;
}