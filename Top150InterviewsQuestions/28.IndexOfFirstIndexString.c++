/*Given two strings needle and haystack, return the index of the first occurrence of needle
 in haystack, or -1 if needle is not part of haystack.Example 1:
Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.
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

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.length();
        int k = needle.length();
        int index = 0;
        for (int i = 0; i < haystack.length(); i++) {
            if (haystack[i] == needle[index]) {
                index++;
            } else{
                  i = i - index;
                  index = 0;
            }
              
            if (index == k) {
                return i - k + 1;
            }
        }
        return -1;
    }
};


int main() {
ios::sync_with_stdio(0);
return 0;
}