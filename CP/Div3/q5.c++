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

    vector<int> L(n + 1), R(n + 1), par(n + 1, 0);
    // Read children for vertices 1 to n
    for (int i = 1; i <= n; i++) {
        cin >> L[i] >> R[i];
        if (L[i] != 0) {
            par[L[i]] = i;
            par[R[i]] = i;
        }
    }
    vector<ll> f(n + 1);
    vector<int> order;
    order.reserve(n);
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int v = q.front(); q.pop();
        order.push_back(v);
        if (L[v] != 0) {
            q.push(L[v]);
            q.push(R[v]);
        }
    }

    // Process in reverse BFS order (leaves first)
    for (int i = (int)order.size() - 1; i >= 0; i--) {
        int v = order[i];
        if (L[v] == 0) {
            f[v] = 1;
        } else {
            f[v] = (f[L[v]] + f[R[v]] + 3) % MOD;
        }
    }

    // Compute time[v] = f[v] + time[parent[v]], time[1] = f[1]
    vector<ll> ans(n + 1);
    for (int v : order) {
        if (v == 1) {
            ans[v] = f[v];
        } else {
            ans[v] = (f[v] + ans[par[v]]) % MOD;
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " \n"[i == n];
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
