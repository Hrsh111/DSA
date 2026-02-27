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
    ll n, h, k;
    cin >> n >> h >> k;
    vll a(n);
    for (auto &x : a) cin >> x;

    ll totalSum = accumulate(all(a), 0LL);
    // prefix sums
    vll pre(n + 1, 0);
    for (int i = 0; i < n; i++) pre[i + 1] = pre[i] + a[i];
    // minPrefix[p] = min of a[0 p-1] (for swapping out from prefix)
    // maxSuffix[p] = max of a[p n-1] (for swapping in from suffix)
    vll minPre(n + 1, LINF);  
    vll maxSuf(n + 1, 0);     
    for (int i = 0; i < n; i++) minPre[i + 1] = min(minPre[i], a[i]);
    for (int i = n - 1; i >= 0; i--) maxSuf[i] = max(maxSuf[i + 1], a[i]);

    // check if we can kill in T seconds
    auto check = [&](ll T) -> bool {
        ll full = T / (n + k);
        ll rem = T - full * (n + k);
        ll partial = min(rem, n);
        ll dmg;
        if (full > 0 && totalSum > h / full) dmg = h; 
        else dmg = full * totalSum + pre[partial];
        if (partial > 0 && partial < n) {
            ll gain = maxSuf[partial] - minPre[partial];
            if (gain > 0) dmg += gain;
        }
        return dmg >= h;
    };

    ll lo = 1, hi = 2LL * (ll)1e18;
    while (lo < hi) {
        ll mid = lo + (hi - lo) / 2;
        if (check(mid)) hi = mid;
        else lo = mid + 1;
    }
    cout << lo << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}