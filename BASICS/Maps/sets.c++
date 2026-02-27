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

/*Level 5: Sets
Sets store unique elements only, automatically sorted.


set<int> s;
s.insert(5);          // add element
s.insert(5);          // ignored — already exists
s.erase(5);           // remove element
s.count(5);           // 1 if exists, 0 if not
s.size();             // number of elements

for(auto& x : s){
    cout << x << " ";
}
unordered_set is faster but unsorted (like unordered_map).

Your exercise: Write a program that:

Takes an array: {4, 2, 7, 2, 4, 9, 7, 1}
Insert all elements into a set
Print the set (should show only unique elements, sorted)
Check if 7 exists in the set and print "Found" or "Not found"
Go!*/

int main() {
//   vector<int> arr={4,2,7,2,4,9,7,1};
  set<int> s={4,2,7,2,4,9,7,1};
  for(int num:s){
    cout<<num<<endl;    
  }
  if(s.count(7)){
            cout<<"FOUND"<<endl;
    }
    else cout<<"NOT FOUND"<<endl;
    // set.count(7); 
    // cout<<"FOUND"<<endl;

    return 0;
}