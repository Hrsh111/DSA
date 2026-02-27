// https://leetcode.com/problems/valid-palindrome/description/
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
    bool isPalindrome(string s) {
        int r = s.length() - 1;
        int l = 0;
        while (l < r) {
            // Skip non-alphanumeric characters from the left side
            while (l < r && !isalnum(s[l])) {
                l++;
            }
            // Skip non-alphanumeric characters from the right side
            while (l < r && !isalnum(s[r])) {
                r--;
            }
            if (tolower(s[l]) != tolower(s[r])) {
                return false;
            } else
                r--;
            l++;
        }
        return true;
    }
};



int main() {
ios::sync_with_stdio(0);
return 0;
}