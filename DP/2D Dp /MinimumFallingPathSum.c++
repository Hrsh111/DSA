/*Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.
A falling path starts at any element in the first row and chooses the element in the next row that is 
either directly below or diagonally left/right. Specifically,
 the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).
 Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
Output: 13
Explanation: There are two falling paths with a minimum sum as shown.
*/
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


 int minFallingPathSum(vector<vector<int> >& matrix) {
    int r= matrix.size();// no of rows
    int c = matrix[0].size();// no of columns
    vector<vector<int> > dp(r, vector<int>(c, 0)) ;
    // filling the first row of the dp with the same elements from the matrix 
    for (int i = 0; i < c; i++)
    {
        dp[0][i]= matrix[0][i];
    }
    // Have to select the min value from the dp first row to proceed further 
    for (int  i = 1; i < r; i++)
    {
            for (int j = 0; j < c; j++)
            {
            // here we have to check for the diff conditions and then chose that value to take the min sum path
          
           int minValue = dp[i-1][j]; // Directly below
            if (j > 0) minValue = min(minValue, dp[i-1][j-1]); // Diagonally left
            if (j < c - 1) minValue = min(minValue, dp[i-1][j+1]); // Diagonally right
            dp[i][j] = matrix[i][j] + minValue;
            }
            
    }
    return *min_element(dp[r-1].begin(), dp[r-1].end());

    

    

        
    }


int main() {
ios::sync_with_stdio(0);
return 0;
}
