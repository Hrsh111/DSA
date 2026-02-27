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
    int n, x, y;
    cin >> n >> x >> y;
    vi p(n);
    rep(i, 0, n) cin >> p[i];
    vi ac, b;
    rep(i, 0, x) ac.pb(p[i]);
    rep(i, x, y) b.pb(p[i]);
    rep(i, y, n) ac.pb(p[i]);

    if (b.empty()) {
        rep(i, 0, n) cout << ac[i] << " \n"[i == n - 1];
        return;
    }

    int minIdx = min_element(all(b)) - b.begin();
    int bLen = sz(b);
    vi bStar(bLen);
    rep(i, 0, bLen) bStar[i] = b[(minIdx + i) % bLen];
    int t = 0;
    while (t < sz(ac) && ac[t] <= bStar[0]) t++;
    vi ans;
    rep(i, 0, t) ans.pb(ac[i]);
    rep(i, 0, bLen) ans.pb(bStar[i]);
    rep(i, t, sz(ac)) ans.pb(ac[i]);

    rep(i, 0, n) cout << ans[i] << " \n"[i == n - 1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}