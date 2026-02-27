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
    int n;
    cin >> n;
    vll f(n + 1);
    rep(i, 1, n + 1) cin >> f[i];
    vll d(n + 1);
    rep(i, 1, n) d[i] = f[i + 1] - f[i];

    ll S = (f[1] + f[n]) / (n - 1);

    vll a(n + 1, 0);
    rep(i, 2, n) {
        a[i] = (d[i] - d[i - 1]) / 2;
    }

    a[1] = (d[1] + S) / 2;

    ll partialSum = 0;
    rep(i, 1, n) partialSum += a[i];
    a[n] = S - partialSum;

    rep(i, 1, n + 1) {
        cout << a[i];
        if (i < n) cout << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
