#include <bits/stdc++.h>
#include <fstream>
#include <sstream>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <deque>
#include <algorithm>
#include <iterator>
#include <cmath>
#include <complex>
#include <utility>
#include <limits>
#include <string>
#include <type_traits>
#include <chrono>
using namespace std;
#include <iostream>
#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define pb push_back
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define rep(i, a, b) for (int i = a; i < b; ++i)
class Solution {
public:
    vector<int> binary(int n, vector<int>& res) {
        // Clear the result vector to avoid leftover data from previous calls
        res.clear();
        
        // Convert the number to binary
        while (n > 0) {
            res.push_back(n % 2);  // Add the remainder (binary digit) to the result vector
            n = n / 2;  // Divide by 2 to move to the next binary digit
        }
        
        // The binary digits are in reverse order, so we reverse the result vector
        reverse(res.begin(), res.end());
        
        return res;
    }

    int hammingWeight(int n) {
        int cnt = 0;
        vector<int> res;
        binary(n, res);  // Get the binary representation of n
        
        // Count the number of 1s in the binary representation
        for (int x : res) {
            if (x == 1) {
                cnt++;
            }
        }
        return cnt;
    }
};
// more concise solution
class Solution {
public:
    int hammingWeight(int n) {
        int count = 0;
        while(n != 0){
            count += n % 2;
            n = n / 2;
        }
        return count;
    }
};



int main() {
ios::sync_with_stdio(0);
return 0;
}