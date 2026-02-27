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

    string smallestNumber(string pattern) {
      // check for the current index element in the pattern and 
      // accordingly swap the elements in the num 
      vector<int> num;
      int n = pattern.length();
      // fill the num first in lexicographical order
      for(int i=1;i<=n+1;i++){
        num.push_back(i);
      }  
      for(int n:num){
        cout<<n<<" ";
      }
    }
};



int main() {
ios::sync_with_stdio(0);
return 0;
}