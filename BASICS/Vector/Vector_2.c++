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

// Level 2: Sorting & Searching on Vectors
// New syntax to learn:

// sort(v.begin(), v.end());           // ascending
// sort(v.begin(), v.end(), greater<int>());  // descending
// reverse(v.begin(), v.end());        // reverse in place
// *min_element(v.begin(), v.end());   // smallest value
// *max_element(v.begin(), v.end());   // largest value
// Your exercise: In the same file (or a new one), write a program that:

// Creates a vector with values {5, 2, 8, 1, 9, 3}
// Prints the min and max element
// Sorts it in ascending order and prints it
// Sorts it in descending order and prints its
// Reverses it and prints it

int main() {
   vector<int> num={5,2,8,1,9,3};
   int min= *min_element(num.begin(), num.end());
   int max= *max_element(num.begin(), num.end());
  // for(int i=num.size()-1; i>=0;i--){
    //cout<<num[i]<<" ";
// }
reverse(num.begin(),num.end());
for(int n:num){
    cout<<" "<<n;
}
cout<<"\n";
   sort(num.begin(), num.end());
   for(int n:num){
    cout<<"Asc order " <<n<<endl;
   }
   sort(num.rbegin(), num.rend());
   for(int n:num){
   cout<<"Desc order "<<n<<endl; 
   }
   cout<<"Min value->"<<min<<" Max element->"<<max<<endl;

    return 0;
}