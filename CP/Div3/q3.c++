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

bool bad(int a, int b) {
    return a == b || a + b == 7;
}

int pickAdj(int prev, int next) {
    for (int x = 1; x <= 6; x++) {
        if (!bad(prev, x) && !bad(x, next)) return x;
    }
    for (int x = 1; x <= 6; x++) {
        if (!bad(prev, x)) return x;
    }
    return 1;
}

void solve() {
    int n;
    cin >> n;
    vi a(n);
    rep(i, 0, n) cin >> a[i];

    int ops = 0;
    for (int i = 0; i + 1 < n; i++) {
        if (bad(a[i], a[i + 1])) {
            ops++;
            int next = (i + 2 < n) ? a[i + 2] : 0;
            a[i + 1] = pickAdj(a[i], next);
        }
    }
    cout << ops << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
