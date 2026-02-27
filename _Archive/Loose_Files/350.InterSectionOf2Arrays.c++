// https://leetcode.com/problems/intersection-of-two-arrays-ii/description/
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
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
       vector<int> res;
       unordered_map<int,int> mp;
       for(int x:nums1){
        mp[x]++;
       } 
       for(int n:nums2){
       if(mp[n]>0){
        res.push_back(n);
        mp[n]--;// decreasing count to handle duplicates 
       }
       }
       return res;
    }
};



int main() {
ios::sync_with_stdio(0);
return 0;
}