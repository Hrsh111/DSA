#include <bits/stdc++.h>
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

/*
Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
Output: 11
Explanation: The triangle looks like:
   2
  3 4
 6 5 7
4 1 8 3
The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).

*/

int minimumTotal(vector<vector<int> >& triangle) {
    int n = triangle.size();

    // Initialize a 2D DP array
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // Fill the last row of DP with the values from the triangle's last row
    for (int j = 0; j < n; ++j) {
        dp[n-1][j] = triangle[n-1][j];
    }

    // Process rows from bottom to top
    for (int i = n-2; i >= 0; --i) {
        for (int j = 0; j <= i; ++j) {
            dp[i][j] = triangle[i][j] + min(dp[i+1][j], dp[i+1][j+1]);
        }
    }

    // The top element contains the result
    return dp[0][0];
}

int main() {
    ios::sync_with_stdio(0);
    return 0;
}
