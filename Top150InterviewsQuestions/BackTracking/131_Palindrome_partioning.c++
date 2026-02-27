//https://leetcode.com/problems/palindrome-partitioning/description/
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

    // Helper function to check if a string is a palindrome
    bool checkPalindrome(string &s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }

    // Recursive function to find all palindrome partitions
    void backtrack(vector<string> &temp, vector<vector<string>> &res, string s) {
        // If the string is empty, add the current partition to the result
        if (s.empty()) {
            res.push_back(temp);
            return;
        }
            
        for (int i = 0; i < s.length(); i++) {
            // Get the substring from 0 to i
            string str = s.substr(0, i + 1);

            // Check if the substring is a palindrome
            if (checkPalindrome(str, 0, str.length() - 1)) {
                // Add the substring to the current partition
                temp.push_back(str);

                // Recur for the remaining part of the string
                backtrack(temp, res, s.substr(i + 1));

                // Backtrack and remove the last added substring
                temp.pop_back();
            }            
        }
    }

    // Main function to partition the string
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;  // To store all partitions
        vector<string> temp;        // To store the current partition
        backtrack(temp, res, s); // Start the recursive process
        return res;
    }
};


int main() {
ios::sync_with_stdio(0);
return 0;
}