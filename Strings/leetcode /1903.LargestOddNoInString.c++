//https://leetcode.com/problems/largest-odd-number-in-string/description/
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
// my code works though (not so logical)
class Solution {
public:
    string largestOddNumber(string num) {
        string empty = "";
        int n = num.length();

        for (char c : num) {
            if (num[n - 1] % 2 != 0)
                return num;
            int digit = c - '0';
            if (digit % 2 != 0) {
                empty += c;
            }
        }
        return empty;
    }
};

// the code in the solutions section (logical)
class Solution {
public:
    string largestOddNumber(string num) {
       for(int i =num.length()-1; i>=0; i--){
        if((num[i]-'0')%2!=0){//checking if the last one is odd or not 
            return num.substr(0, i+1);
        }
       }
       return "";
    }
};



int main() {
ios::sync_with_stdio(0);
return 0;
}