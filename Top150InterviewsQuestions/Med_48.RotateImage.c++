//https://leetcode.com/problems/rotate-image/description/
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
    void rotate(vector<vector<int>>& matrix) {
        int r= matrix.size();
        // transpose of the matrix 
        for(int i =0;i<r;i++){
            for(int j=0;j<=i;j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        // swap the rows for completion of 90 degrees
        for(int i=0;i<r;i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};



int main() {
ios::sync_with_stdio(0);
return 0;
}