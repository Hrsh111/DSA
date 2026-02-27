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
/*
Level 4: Maps
Maps are key-value stores — super important for frequency counting, lookups, etc.
map<string, int> m;
m["apple"] = 5;           // insert or update
m["banana"] = 3;
m.count("apple");         // 1 if exists, 0 if not
m.erase("apple");         // remove key
m.size();                 // number of entries
loop through map
for(auto& [key, val] : m){
    cout << key << " -> " << val << endl;
}
Key thing: map keeps keys sorted. unordered_map is faster but unsorted.
Your exercise: Write a program that:
Takes a string as input (e.g. "hello")
Counts the frequency of each character using a map<char, int>
Prints each character and its count
Example output for "hello":
e -> 1
h -> 1
l -> 2
o -> 1
Go!

*/

int main() {
    string s;
    cout<<"Your input"<<endl;
    cin>>s;
   unordered_map<char,int> mp;
   int size=s.size();
    for(auto charr:s){
        mp[charr]++;
    }
    for(auto &[ch,count]:mp)
   cout<<ch<<"->"<<count<<endl;

    return 0;
}