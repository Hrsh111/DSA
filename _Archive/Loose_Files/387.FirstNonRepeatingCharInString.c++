//https://leetcode.com/problems/first-unique-character-in-a-string/
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
    int firstUniqChar(string s) {
     int n = s.length();
     unordered_map<char ,int> mp;
     for(int i=0;i<n;i++){
        mp[s[i]]++;
     }
     for(int i=0; i<n;i++){
        if(mp[s[i]]==1){
            return i;
        }
     }
    return -1;
    }
    
};


int main() {
ios::sync_with_stdio(0);
return 0;
}
