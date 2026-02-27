//https://leetcode.com/problems/longest-palindromic-substring/description/
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
    string longestPalindrome(string s) {
        if(s.length()<=1) return s;
        string LPS="";
        // here checked the left and right if they are equal
        // means they can form a palindromic substring 
        for(int i =1;i<s.length();i++){
            // considering the length of the string to be even
            int low=i;
            int high =i;
            while(low>=0 && high<s.length() && s[low]==s[high]){
                low--;
                high++;
            }
            // extract that substring 
            string palindrome= s.substr(low+1 , high-low-1);
            if(palindrome.length()>LPS.length()){
                LPS=palindrome;
            }
            // here considering the length of the string to be even

            low=i-1;
            high =i;
            while(low>=0 && high<s.length() && s[low]==s[high]){
                low--;
                high++;
            }
            // again extract the length of the palindromic subsequence 
            string palindromeEven=s.substr(low+1, high-low-1);
            if(palindromeEven.length()>LPS.length()){
                LPS=palindromeEven;
            }
        }
        return LPS;
    }
};


int main() {
ios::sync_with_stdio(0);
return 0;
}

