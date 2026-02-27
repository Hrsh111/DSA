//https://leetcode.com/problems/letter-tile-possibilities/description/?envType=problem-list-v2&envId=backtracking
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
    void backtrack(string tiles, int start, int &count) {
        count++;
        for (int i = start; i < tiles.length(); i++) {
            if (i != start && tiles[i] == tiles[start]) continue;
            swap(tiles[i], tiles[start]);
            backtrack(tiles, start + 1, count);
        }
    }

    int numTilePossibilities(string tiles) {
        int count = -1;  
        sort(tiles.begin(), tiles.end());  
        backtrack(tiles, 0, count);
        return count;
    }
};




int main() {
ios::sync_with_stdio(0);
return 0;
}