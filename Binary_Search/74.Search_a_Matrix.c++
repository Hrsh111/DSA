//https://leetcode.com/problems/search-a-2d-matrix/
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
        bool searchMatrix(vector<vector<int>>& matrix, int target) {
            int r = matrix.size();
            int c = matrix[0].size();
            int l = 0;
            int h = (r * c)-1;
            while (l <= h) {
                int mid = l+(h-l) / 2;
                int mr = mid / c; // get the row index
                int mc = mid % c; // get the col index
    
                if (matrix[mr][mc] == target) {
                    return true;
                } else if (target > matrix[mr][mc]) {
                    l = mid + 1;//move right
                } else {
                    h = mid - 1;// move left
                }
            }
            return false;
        }
    };



int main() {
ios::sync_with_stdio(0);
return 0;
}