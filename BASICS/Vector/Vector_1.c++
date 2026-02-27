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
// TASK
// Creates an empty vector of ints
// Pushes 5 numbers into it (any numbers)
// Prints all elements using a range-based for loop
// Prints the size
// Removes the last element
// Prints all elements again

int main()
{
    vector<int> num;
    num.push_back(17);
    num.push_back(16);
    num.push_back(1);
    num.push_back(12);
    num.push_back(11);

    for (int k : num)
    {
        cout << k << " ";
    }
    int size = num.size();
    cout << "\n";
    num.pop_back();
    for (int z : num)
    {
        cout << z << endl;
    }

    cout << "Size "<<size << endl;






    return 0;
}