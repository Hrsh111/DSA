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
    string x;
    cin >> x;
    int lo = 1, hi = 1;
    bool ho = true, he = false;

    for (int i = 0; i < n; i++) {
        char c = x[i]; 
        int lo_odd = (lo % 2 == 1) ? lo : lo + 1;
        int hi_odd = (hi % 2 == 1) ? hi : hi - 1;
        bool real_ho = ho && (lo_odd <= hi_odd);

        int lo_even = (lo % 2 == 0) ? lo : lo + 1;
        int hi_even = (hi % 2 == 0) ? hi : hi - 1;
        bool real_he = he && (lo_even <= hi_even);
        if (!real_ho && !real_he) {
            cout << "NO\n";
            return;
        }

        bool same_parity = ((n + i) % 2 == 1);

        int new_lo = INF, new_hi = -1;
        bool new_ho = false, new_he = false;

        if (same_parity) {
            bool odd_survive = real_ho && (c == 'a' || c == '?');
            bool even_survive = real_he && (c == 'b' || c == '?');

            if (!odd_survive && !even_survive) {
                cout << "NO\n";
                return;
            }
            if (odd_survive) {
                new_lo = min(new_lo, lo_odd);
                new_hi = max(new_hi, hi_odd + 1);
            }
            if (even_survive) {
                new_lo = min(new_lo, lo_even);
                new_hi = max(new_hi, hi_even + 1);
            }
            new_ho = true;
            new_he = true;

        } else {
            if (c == '?') {
                if (real_ho) {
                    new_lo = min(new_lo, lo_odd);
                    new_hi = max(new_hi, hi_odd + 1);
                }
                if (real_he) {
                    new_lo = min(new_lo, lo_even);
                }
                new_ho = true;
                new_he = true;
                
            } else if (c == 'a') {
                new_hi = max(new_hi, hi_even + 1);
                bool have_any = false;
                if (real_ho) {
                    new_lo = min(new_lo, lo_odd + 1);
                    new_hi = max(new_hi, hi_odd + 1);
                    have_any = true;
                }
                if (real_he) {
                    new_lo = min(new_lo, lo_even);
                    new_hi = max(new_hi, hi_even);
                    have_any = true;
                }
                if (!have_any) {
                    cout << "NO\n";
                    return;
                }
                new_ho = false;
                new_he = true;

            } else { 
                bool have_any = false;
                if (real_ho) {
                    new_lo = min(new_lo, lo_odd);
                    new_hi = max(new_hi, hi_odd);
                    have_any = true;
                }
                if (real_he) {
                    new_lo = min(new_lo, lo_even + 1);
                    new_hi = max(new_hi, hi_even + 1);
                    have_any = true;
                }
                if (!have_any) {
                    cout << "NO\n";
                    return;
                }
                new_ho = true;
                new_he = false;
            }
        }

        lo = new_lo;
        hi = new_hi;
        ho = new_ho;
        he = new_he;
    }
    int lo_odd = (lo % 2 == 1) ? lo : lo + 1;
    int hi_odd = (hi % 2 == 1) ? hi : hi - 1;
    bool real_ho = ho && (lo_odd <= hi_odd);
    int lo_even = (lo % 2 == 0) ? lo : lo + 1;
    int hi_even = (hi % 2 == 0) ? hi : hi - 1;
    bool real_he = he && (lo_even <= hi_even);

    if (real_ho || real_he) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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