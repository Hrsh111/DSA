// https://leetcode.com/problems/remove-outermost-parentheses/
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
// using stack
class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<int> st;
        string result = "";
        for (char c : s) {
            if (c == '(') {
                // check if the stack is empty or not
                if (!st.empty()) {
                    result += c;
                }
                st.push(c);
            }
            if (c == ')') {
                st.pop();
                // stack not empty means not outer bracket
                if (!st.empty()) {
                    result += c;
                }
            }
        }
        return result;
    }
};
// without using the stack
class Solution {
public:
    string removeOuterParentheses(string s) {
        string res;
        int count=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(' && count==0)
                count++;
            else if(s[i]=='(' && count>=1){
                res+=s[i];
                count++;
            }   
            else if(s[i]==')' && count>1){
                res+=s[i];
                count--;
            }
            else if(s[i]==')' && count==1)
                count--;
        }
        return res;
    }
};


int main() {
ios::sync_with_stdio(0);
return 0;
}