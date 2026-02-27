// #include <bits/stdc++.h>
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


      int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        queue<pair<int, int>> q; // Queue to store {row, col} of rotten oranges
        int freshCount = 0;     // Count of fresh oranges
        int time = 0;           // Track the time (minutes) elapsed

        // Step 1: Initialize the queue with all rotten oranges
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j}); // Add rotten orange to queue
                } else if (grid[i][j] == 1) {
                    freshCount++; // Count fresh oranges
                }
            }
        }

        // If there are no fresh oranges, no time is needed
        if (freshCount == 0) return 0;

        // Step 2: BFS Traversal
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // 4 possible directions

        while (!q.empty()) {
            int size = q.size(); // Number of rotten oranges to process in this minute
            bool anyFreshRotted = false;

            for (int i = 0; i < size; i++) {
                auto [x, y] = q.front(); // storing the coordinates of the element that needs to be rooten in x and y so that it can be used to 
                // change the direction further and rot the other oranges 
                q.pop();

                // Spread the rot to all 4 directions
                for (auto dir : directions) {
                    int nx = x + dir.first; // New row
                    int ny = y + dir.second; // New col

            // Check if the new position is valid and has a fresh orange
    if (nx >= 0 && ny >= 0 && nx < rows && ny < cols && grid[nx][ny] == 1) {
                        grid[nx][ny] = 2; // Make the orange rotten
                        q.push({nx, ny}); // Add it to the queue
                        freshCount--;     // Decrease the fresh orange count
                        anyFreshRotted = true;
                    }
                }
            }

            if (anyFreshRotted) time++; // Increment time if any fresh oranges rotted
        }

        // Step 3: Return result
        return freshCount == 0 ? time : -1; // If freshCount > 0, it's impossible to rot all oranges
    };




int main() {
ios::sync_with_stdio(0);
return 0;
}