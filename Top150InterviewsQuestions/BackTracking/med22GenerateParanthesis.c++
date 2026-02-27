// https://leetcode.com/problems/generate-parentheses/description/
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
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string current="";
        backtracking(res,current,0,0,n);
        return res;
    }
    void backtracking(vector<string>& res, string current, int open, int close,
                      int n) {
        // base case if the string has been formed completely
        if (open == n && close == n) {
            res.push_back(current);
            return;
        }
        // case2 push '(' when the val of open is not 0
        if (open < n) {
            backtracking(res, current + '(', open + 1, close, n);
        }
        // case3 when open>close push )
        if (open > close) {
            backtracking(res, current + ')', open, close + 1, n);
        }
    }
};


int main() {
ios::sync_with_stdio(0);
return 0;
}