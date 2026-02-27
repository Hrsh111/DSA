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

struct LCNode {
    ll m, b;
    int left, right;
};

const int POOL_SZ = 6000000;
LCNode pool[POOL_SZ];
int pool_cnt;

int alloc_node() {
    pool[pool_cnt] = {0, -LINF, -1, -1};
    return pool_cnt++;
}

int MAXC; 

void lct_insert(int &nd, int l, int r, ll m, ll b) {
    if (nd == -1) {
        nd = alloc_node();
        pool[nd].m = m;
        pool[nd].b = b;
        return;
    }

    ll lnew = m * l + b, rnew = m * r + b;
    ll lcur = pool[nd].m * l + pool[nd].b, rcur = pool[nd].m * r + pool[nd].b;

    if (lnew >= lcur && rnew >= rcur) {
        pool[nd].m = m; pool[nd].b = b;
        return;
    }
    if (lnew <= lcur && rnew <= rcur) return;

    int mid = (l + r) >> 1;
    ll mnew = m * mid + b, mcur = pool[nd].m * mid + pool[nd].b;

    if (mnew > mcur) {
        ll tm = pool[nd].m, tb = pool[nd].b;
        pool[nd].m = m; pool[nd].b = b;
        m = tm; b = tb;
        // Recalc after swap
        lnew = m * l + b;
        if (lnew > pool[nd].m * l + pool[nd].b)
            lct_insert(pool[nd].left, l, mid, m, b);
        else
            lct_insert(pool[nd].right, mid + 1, r, m, b);
    } else {
        if (lnew > lcur)
            lct_insert(pool[nd].left, l, mid, m, b);
        else
            lct_insert(pool[nd].right, mid + 1, r, m, b);
    }
}

ll lct_query(int nd, int l, int r, ll x) {
    if (nd == -1) return -LINF;
    ll res = pool[nd].m * x + pool[nd].b;
    if (l == r) return res;
    int mid = (l + r) >> 1;
    if (x <= mid)
        return max(res, lct_query(pool[nd].left, l, mid, x));
    else
        return max(res, lct_query(pool[nd].right, mid + 1, r, x));
}

void solve() {
    int n;
    cin >> n;

    vll a(n + 1);
    rep(i, 1, n + 1) cin >> a[i];

    vvi adj(n + 1);
    rep(i, 0, n - 1) {
        int u, v; cin >> u >> v;
        adj[u].pb(v); adj[v].pb(u);
    }

    if (n == 1) { cout << "0\n"; return; }

    // BFS
    vi par(n + 1, 0), dep(n + 1, 0), order;
    order.reserve(n);
    vector<bool> vis(n + 1, false);
    queue<int> bfsq;
    bfsq.push(1); vis[1] = true;
    while (!bfsq.empty()) {
        int u = bfsq.front(); bfsq.pop();
        order.pb(u);
        for (int v : adj[u]) if (!vis[v]) {
            vis[v] = true; par[v] = u; dep[v] = dep[u] + 1;
            bfsq.push(v);
        }
    }

    vvi ch(n + 1);
    for (int u : order)
        for (int v : adj[u]) if (v != par[u]) ch[u].pb(v);

    vll S(n + 1), adsum(n + 1);
    vi maxdep(n + 1), secdep(n + 1), subsz(n + 1);

    for (int i = n - 1; i >= 0; i--) {
        int u = order[i];
        S[u] = a[u]; adsum[u] = a[u] * dep[u];
        maxdep[u] = secdep[u] = dep[u]; subsz[u] = 1;
        for (int c : ch[u]) {
            S[u] += S[c]; adsum[u] += adsum[c]; subsz[u] += subsz[c];
            if (maxdep[c] >= maxdep[u]) { secdep[u] = maxdep[u]; maxdep[u] = maxdep[c]; }
            else if (maxdep[c] > secdep[u]) secdep[u] = maxdep[c];
        }
    }
    vi h(n + 1, 0);
    for (int i = 1; i < n; i++) {
        int v = order[i], p = par[v];
        h[v] = (maxdep[v] == maxdep[p]) ? secdep[p] : maxdep[p];
    }
    MAXC = maxdep[order[0]] + 2; 

    vll basecost(n + 1);
    rep(i, 0, n) { int r = order[i]; basecost[r] = adsum[r] - (ll)dep[r] * S[r]; }


    vi lct_rt(n + 1, -1);
    vector<vector<pair<ll,ll>>> lns(n + 1); 
    vll best_gain(n + 1, 0);

    for (int i = n - 1; i >= 0; i--) {
        int u = order[i];

        if (ch[u].empty()) {
            lct_rt[u] = -1;
            ll m = S[u], b = -S[u] * dep[u];
            lct_insert(lct_rt[u], 0, MAXC, m, b);
            lns[u].push_back({m, b});
            continue;
        }

        int heavy = ch[u][0];
        for (int c : ch[u]) if (lns[c].size() > lns[heavy].size()) heavy = c;

        ll best = 0;
        for (int c : ch[u]) {
            ll x = h[c] + 1;
            ll q = lct_query(lct_rt[c], 0, MAXC, x);
            best = max(best, q);
            best = max(best, best_gain[c]);
        }

        lct_rt[u] = lct_rt[heavy];
        lns[u] = std::move(lns[heavy]);

        for (int c : ch[u]) {
            if (c == heavy) continue;
            if (lns[c].size() > lns[u].size()) {
                
                swap(lct_rt[u], lct_rt[c]);
                swap(lns[u], lns[c]);
            }
           
            for (auto [m, b] : lns[c]) {
                lct_insert(lct_rt[u], 0, MAXC, m, b);
                lns[u].push_back({m, b});
            }
            lns[c].clear(); lns[c].shrink_to_fit();
            
        }

        ll m = S[u], b = -S[u] * dep[u];
        lct_insert(lct_rt[u], 0, MAXC, m, b);
        lns[u].push_back({m, b});

        best_gain[u] = best;
    }

    rep(i, 1, n + 1) {
        cout << basecost[i] + max(0LL, best_gain[i]);
        cout << " \n"[i == n];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--) {
        pool_cnt = 0; 
        solve();
    }
    return 0;
}
