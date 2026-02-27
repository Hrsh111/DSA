//https://leetcode.com/problems/excel-sheet-column-number/description/
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
    int titleToNumber(string columnTitle) {
        int res=0;
        for(char c:columnTitle){
            res= res*26+(c-'A'+1);
        }
        return res;
    }
};
// A->1 .. AB-> 1*26+2=28.. ZY-> 26*26+25=701.. XY->24*26+25=649


int main() {
ios::sync_with_stdio(0);
return 0;
}