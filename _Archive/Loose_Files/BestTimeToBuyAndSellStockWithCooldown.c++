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
    int maxProfit(vector<int>& prices) {
         int n=prices.size();
        if(n<=1) return 0;
        int buy=-prices[0];
        int sell=0;
        int prev_sell=0;
        for(int i=0;i<n;i++){
            int old_buy=buy;
            buy=max(buy,prev_sell-prices[i]);
            prev_sell=sell;
            
            sell=max(sell,old_buy+prices[i]);
        }
        return sell;
    }
};