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
    int longestCommonSubsequence(string text1, string text2) {
        int l1= text1.size();
        int l2= text2.size();
        vector<vector<int>> dp(l1+1, vector<int>(l2+1,0));
        if(l1==0 || l2==0) return 0;
        for(int i=1;i<=l1;i++){
            for(int j=1;j<=l2;j++){
                if(text1[i-1]==text2[j-1]) 
                dp[i][j]= 1+dp[i-1][j-1];
                else 
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[l1][l2];
    }
};



int main() {
ios::sync_with_stdio(0);
return 0;
}