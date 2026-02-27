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
    vi a(n);
    rep(i, 0, n) cin >> a[i];

    // Stack of (base_value, count)
    // base_value is strictly increasing from bottom to top
    vector<pii> stk; // (base_val, count)
    ll total_count = 0; // sum of all counts in stack
    ll ans = 0;

    rep(i, 0, n) {
        int v = a[i];
        ll root_count;

        if (i == 0 || v > a[i-1] + 1) {
            // v-1 > top = a[i-1], so ALL existing left endpoints give root
            root_count = total_count + 1;
            stk.clear();
            total_count = 0;
        } else {
            // v <= a[i-1] + 1, so v-1 <= a[i-1] = top
            // Pop entries with base_val >= v
            ll popped = 0;
            while (!stk.empty() && stk.back().ff >= v) {
                popped += stk.back().ss;
                total_count -= stk.back().ss;
                stk.pop_back();
            }
            root_count = popped + 1;
        }

        stk.pb({v, (int)root_count});
        total_count += root_count;
        ans += root_count * (ll)(n - i);
    }

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}