#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
#include <cmath>
#include <climits>
#include <numeric>
using namespace std;
#define ll long long
#define ld long double
#define vi vector<int>
#define vll vector<long long>
#define vvi vector<vector<int>>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define pb push_back
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)

const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;

// Vector of pairs: {(3,5), (1,9), (3,2), (1,4)}
// Print all pairs as (first, second)
// Sort and print again
// Remember: pair<int,int>, .first, .second, push_back({x,y}). Go!
int main() {
   vector<pair<int,int>> pairs={{3,5},{1,9},{3,2},{1,4}};
   for(auto pair:pairs){
    cout<<"{"<<pair.first<<","<<pair.second<<"}"<<" ";
   }
   sort(pairs.begin(),pairs.end());
   cout<<"\n";
   for(auto pair:pairs){
       cout<<"Sorted "<<"{"<<pair.first<<","<<pair.second<<"}"<<endl;
   }

    return 0;
}