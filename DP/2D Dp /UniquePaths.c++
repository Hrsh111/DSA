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
There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]).
 The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). 
The robot can only move either down or right at any point in time.
Given the two integers m and n, return the number of possible unique paths that the
 robot can take to reach the bottom-right corner.
 Input: m = 3, n = 7
Output: 28
Example 2:

Input: m = 3, n = 2
Output: 3
Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down
*/

int uniquePaths(int m, int n) {
    vector<vector<int>> dpgrid(m, vector<int>(n, 0));// intializing a 2D dynamic vector 
    
        for (int i = 0; i < m; i++)
        {
            dpgrid[0][i]=1;
        }
        for (int i = 0; i < m; i++)
        {
            dpgrid[i][0]=1;
        }

        for (int  i = 1; i < m; i++)
        {
                for (int j = 1; j < n; j++)
                {
                   dpgrid[i][j]=dpgrid[i-1][j]+dpgrid[i][j-1];
                }
               
        }
         return dpgrid[m-1][n-1];
        

        
    }


int main() {
ios::sync_with_stdio(0);
return 0;
}