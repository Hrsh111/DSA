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
    string s;
    cin >> s;

    if (n % 2) {
        cout << "NO\n";
        return;
    }

    vector<bool> dp(n + 1, false);
    dp[0] = true;

    rep(i, 0, n) {
        if (!dp[i]) continue;
        vector<char> stk;
        for (int j = i; j < n; j++) {
            if (!stk.empty() && stk.back() == s[j])
                stk.pop_back();
            else
                stk.pb(s[j]);
            if (stk.empty())
                dp[j + 1] = true;
        }
    }

    cout << (dp[n] ? "YES" : "NO") << "\n";
}


int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}