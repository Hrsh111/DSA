//https://leetcode.com/problems/non-overlapping-intervals/description/
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
static bool cmp(vector<int>& a,vector<int>& b){
    return a[1]<b[1];
}

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        int n = intervals.size();
        sort(intervals.begin(),intervals.end(),cmp);
        int prev_ele=0;
        int cunt=1;
        for(int i=1; i < n; i++){
            if(intervals[i][0]>=intervals[prev_ele][1]){
                prev_ele=i;
                cunt++;
            }
        }
        return n - cunt;
        
    }
};


int main() {
ios::sync_with_stdio(0);
return 0;
}