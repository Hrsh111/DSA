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

void solve() {
    int n;cin>>n;
    vi a(n);
    // first find the largest element 
    int maxelement;
    rep(i,0,n){
        cin>>a[i];
    }
    maxelement=*max_element(a.begin(), a.end());
    int r=-1;
    rep(i,0,n){
        if(a[i]==maxelement){
            r=i;
        }
    }
    int l=0;
    reverse(a.begin()+l, a.begin()+r+1);
    rep(i,0,n){
        cout<<a[i];
        if(i<n-1)cout<<" ";
    }
    cout<<"\n";
    

}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}