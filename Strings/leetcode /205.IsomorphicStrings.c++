//https://leetcode.com/problems/isomorphic-strings/
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
/*approach 
1. make 2 arrays to check for the occurence one for char in s and one for char in t 
2. If both values are not mapped then first map
3.check if already mapped and if mapping twice to some other char then return false 
*/
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length()!=t.length()) return false;
       vector<int> s2t(256,0), t2s(256,0);
       for(int i=0; i<s.length();i++){
            if(s2t[s[i]]==0 && t2s[t[i]]==0){// checking here whether mapped first or not 
                s2t[s[i]]=t[i];// if not then map 
                t2s[t[i]]=s[i];// if not then map
            }
            else if(s2t[s[i]]!=t[i]){
                // contradict mapping 
                return false;
            }
       }
       return true;
    }
};



int main() {
ios::sync_with_stdio(0);
return 0;
}