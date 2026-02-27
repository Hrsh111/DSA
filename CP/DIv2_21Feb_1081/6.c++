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

const ll MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;

ll power(ll base, ll exp, ll mod) {
    ll res = 1; base %= mod;
    while (exp > 0) {
        if (exp & 1) res = res * base % mod;
        base = base * base % mod;
        exp >>= 1;
    }
    return res;
}

ll inv2 = power(2, MOD - 2, MOD);

int N, X, Y;
ll A[3001], B[3001];
ll cumB_al[3001], cumB_ar[3001], cumB_bl[3001], cumB_br[3001];
int maxEl, maxBr, gap;

unordered_map<ll, ll> memo;

ll encode(int el, int er, int bl, int br, int turn) {
    // each dimension fits in 12 bits (max 3000)
    return ((ll)el << 49) | ((ll)er << 37) | ((ll)bl << 25) | ((ll)br << 13) | ((ll)turn << 12);
}

ll rec(int el, int er, int bl, int br, int turn) {
    ll key = encode(el, er, bl, br, turn);
    auto it = memo.find(key);
    if (it != memo.end()) return it->second;

    ll sizeA = A[X] + cumB_al[el] + cumB_ar[er];
    ll sizeB = A[Y] + cumB_bl[bl] + cumB_br[br];

    ll res;

    if (turn == 0) { // Alice's turn (fish at X)
        // Left neighbor
        bool canLeft = false;
        if (el < maxEl) canLeft = (sizeA >= A[X - el - 1]);

        // Right neighbor
        bool canRight = false;
        bool rightIsBob = (er + bl >= gap);

        if (!rightIsBob) {
            canRight = (sizeA >= A[X + er + 1]);
        } else {
            canRight = (sizeA >= sizeB);
        }

        if (!canLeft && !canRight) {
            res = 0; // Alice can't eat -> Alice loses
        } else if (canLeft && canRight) {
            ll pL, pR;
            if (rightIsBob) {
                pL = rec(el + 1, er, bl, br, 1);
                pR = 1; // eat Bob -> win
            } else {
                pL = rec(el + 1, er, bl, br, 1);
                pR = rec(el, er + 1, bl, br, 1);
            }
            res = (pL + pR) % MOD * inv2 % MOD;
        } else if (canLeft) {
            res = rec(el + 1, er, bl, br, 1);
        } else { // canRight only
            if (rightIsBob) {
                res = 1; // eat Bob -> win
            } else {
                res = rec(el, er + 1, bl, br, 1);
            }
        }
    } else { // Bob's turn (fish at Y)
        // Right neighbor
        bool canRight = false;
        if (br < maxBr) canRight = (sizeB >= A[Y + br + 1]);

        // Left neighbor
        bool canLeft = false;
        bool leftIsAlice = (er + bl >= gap);

        if (!leftIsAlice) {
            canLeft = (sizeB >= A[Y - bl - 1]);
        } else {
            canLeft = (sizeB >= sizeA);
        }

        if (!canLeft && !canRight) {
            res = 1; // Bob can't eat -> Bob loses -> Alice wins
        } else if (canLeft && canRight) {
            ll pL, pR;
            if (leftIsAlice) {
                pL = 0; // eat Alice -> Alice loses
                pR = rec(el, er, bl, br + 1, 0);
            } else {
                pL = rec(el, er, bl + 1, br, 0);
                pR = rec(el, er, bl, br + 1, 0);
            }
            res = (pL + pR) % MOD * inv2 % MOD;
        } else if (canLeft) {
            if (leftIsAlice) {
                res = 0; // eat Alice -> Alice loses
            } else {
                res = rec(el, er, bl + 1, br, 0);
            }
        } else { // canRight only
            res = rec(el, er, bl, br + 1, 0);
        }
    }

    memo[key] = res;
    return res;
}

void solve() {
    int n;
    cin >> n;
    N = n;
    int x, y;
    cin >> x >> y;
    x--; y--;

    for (int i = 0; i < n; i++) cin >> A[i];
    for (int i = 0; i < n; i++) cin >> B[i];

    bool swapped = false;
    if (x > y) {
        swap(x, y);
        swapped = true;
    }
    X = x; Y = y;

    gap = Y - X - 1;
    maxEl = X;
    maxBr = N - 1 - Y;

    cumB_al[0] = 0;
    for (int i = 1; i <= maxEl; i++) cumB_al[i] = cumB_al[i-1] + B[X - i];
    cumB_ar[0] = 0;
    for (int i = 1; i <= gap; i++) cumB_ar[i] = cumB_ar[i-1] + B[X + i];
    cumB_bl[0] = 0;
    for (int i = 1; i <= gap; i++) cumB_bl[i] = cumB_bl[i-1] + B[Y - i];
    cumB_br[0] = 0;
    for (int i = 1; i <= maxBr; i++) cumB_br[i] = cumB_br[i-1] + B[Y + i];

    memo.clear();

    if (!swapped) {
        cout << rec(0, 0, 0, 0, 0) << "\n";
    } else {
        // After swap: X = original Bob, Y = original Alice
        // turn 0 = X's turn = original Bob's turn
        // turn 1 = Y's turn = original Alice's turn
        // Original Alice goes first = turn 1
        // rec returns P(X-player wins) = P(original Bob wins)
        // P(original Alice wins) = 1 - rec(0,0,0,0,1)
        ll r = rec(0, 0, 0, 0, 1);
        cout << (1 - r + MOD) % MOD << "\n";
    }
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
