// https://leetcode.com/problems/generate-binary-strings-without-adjacent-zeros/?envType=problem-list-v2&envId=backtracking
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
    void backtrack(vector<string>& res, string current, int n){
        // base case 
        if(current.size()==n){
            res.push_back(current);
            return;
        }
        // pick 1 always valid
        backtrack( res,current+"1",n);
        //pick 0 only if the prev element not 0
        if(current.empty()|| current.back()!='0'){
            backtrack(res,current+"0",n);
        }
    }
    vector<string> validStrings(int n) {
        vector<string> res;
        backtrack(res,"",n);
        return res;
    }
};



int main() {
ios::sync_with_stdio(0);
return 0;
}
