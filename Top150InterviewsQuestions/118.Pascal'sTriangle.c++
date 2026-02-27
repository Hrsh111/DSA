// https://leetcode.com/problems/pascals-triangle/description/
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
    vector<vector<int>> generate(int numRows) {
        int r = numRows;
        int c = numRows;
        vector<vector<int>> dp(r, vector<int>(c, 0)); // Initialize with 0s

        // Set the 0th column values to 1
        for (int i = 0; i < r; i++) {
            dp[i][0] = 1;
        }

        // Fill the Pascal's Triangle
        for (int i = 1; i < r; i++) {
            for (int j = 1; j < c; j++) {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            }
        }

        // Remove trailing 0s from each row
        for (int i = 0; i < r; i++) {
            dp[i].resize(i + 1); // Resize each row to (i + 1) elements
        }

        return dp;
    }
};




int main() {
ios::sync_with_stdio(0);
return 0;
}