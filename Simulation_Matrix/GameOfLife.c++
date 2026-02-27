// https://leetcode.com/problems/game-of-life/
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
    void gameOfLife(vector<vector<int>>& board) {
        vector<pair<int,int>> directions = {
            {1, 0}, {1, -1}, {0, -1}, {-1, -1}, 
            {-1, 0}, {-1, 1}, {0, 1}, {1, 1}
        };
        
        int rows = board.size();
        int columns = board[0].size();
        
        // First pass: mark the cells with special values for state changes
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                int live = 0;
                // Count live neighbours
                for (auto dir : directions) {
                    int nx = i + dir.first;
                    int ny = j + dir.second;
                    if (nx >= 0 && nx < rows && ny >= 0 && ny < columns && abs(board[nx][ny]) == 1) {
                        live++;
                    }
                }
                // Apply the rules
                if (board[i][j] == 1 && (live < 2 || live > 3)) {
                    board[i][j] = -1;  // mark as -1 to indicate cell was live and now dead 
                }
                if (board[i][j] == 0 && live == 3) {
                    board[i][j] = 2;   // mark as 2 to indicate cell was dead and now live
                }
            }
        }
        
        // Second pass: finalize the state changes for the entire board
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                if (board[i][j] > 0) {
                    board[i][j] = 1;
                } else {
                    board[i][j] = 0;
                }
            }
        }
    }
};
