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
    void backtrack(vector<int>& candidates, int target, int currsum, int index,
                   vector<int>& temp, vector<vector<int>>& res) {
        if (currsum == target) {
            res.push_back(temp); // Found a valid combination
            return;
        }
        if (currsum > target)
            return; // Exceeded the target, stop further exploration

        for (int i = index; i < candidates.size(); i++) {
            // Skip duplicates
            if (i > index && candidates[i] == candidates[i - 1])
                continue;

            // Include candidates[i] in the current combination
            temp.push_back(candidates[i]);
            backtrack(candidates, target, currsum + candidates[i], i + 1, temp,
                      res);
            temp.pop_back(); // Backtrack: remove the last element to explore
                             // other possibilities
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> temp;

        // Sort candidates to handle duplicates
        sort(candidates.begin(), candidates.end());

        // Start backtracking
        backtrack(candidates, target, 0, 0, temp, res);

        return res;
    }
};




int main() {
ios::sync_with_stdio(0);
return 0;
}