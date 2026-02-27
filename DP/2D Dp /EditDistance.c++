// https://leetcode.com/problems/edit-distance/
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

int main()
{
    ios::sync_with_stdio(0);
    return 0;
}
class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int L1 = word1.length();
        int L2 = word2.length();
        vector<vector<int>> dp(L1 + 1, vector<int>(L2 + 1));
        for (int i = 1; i <= L1; i++)
            dp[i][0] = i;
        for (int j = 1; j <= L2; j++)
            dp[0][j] = j;
        for (int i = 1; i <= L1; i++)
            for (int j = 1; j <= L2; j++)
                if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1;
        return dp[L1][L2];
    }
};