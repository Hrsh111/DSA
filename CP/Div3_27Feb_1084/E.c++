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
const int MAXV = 1e6 + 1;

int spf[MAXV]; 

void sieve() {
    for (int i = 0; i < MAXV; i++) spf[i] = i;
    for (int i = 2; (ll)i * i < MAXV; i++) {
        if (spf[i] == i) { 
            for (int j = i * i; j < MAXV; j += i) {
                if (spf[j] == j) spf[j] = i;
            }
        }
    }
}
int countDistinctPrimes(int x, int &prime) {
    if (x == 1) { prime = 0; return 0; }
    int cnt = 0;
    prime = 0;
    while (x > 1) {
        int p = spf[x];
        if (p != prime) {
            cnt++;
            prime = p;
        }
        while (x > 1 && spf[x] == p) x /= p;
    }
    return cnt;
}

void solve() {
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++) cin >> a[i];


    bool nonDec = true;
    for (int i = 0; i + 1 < n; i++) {
        if (a[i] > a[i + 1]) { nonDec = false; break; }
    }
    if (nonDec) { cout << "Bob\n"; return; }

    vi key(n);
    for (int i = 0; i < n; i++) {
        int prime;
        int dpc = countDistinctPrimes(a[i], prime);
        if (dpc >= 2) {
            cout << "Alice\n";
            return;
        }
     
        key[i] = prime;
    }
    bool keysNonDec = true;
    for (int i = 0; i + 1 < n; i++) {
        if (key[i] > key[i + 1]) { keysNonDec = false; break; }
    }

    if (keysNonDec) {
        cout << "Bob\n";
    } else {
        cout << "Alice\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
