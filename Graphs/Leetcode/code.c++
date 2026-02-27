#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

const int MOD = 1e9 + 7;


int countPaths(vector<vector<int>>& grid, int k) {
    int m = grid.size();
    int n = grid[0].size();
    

    vector<vector<unordered_map<int, int>>> dp(m, vector<unordered_map<int, int>>(n));


    dp[0][0][grid[0][0]] = 1;


    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            

            for (auto& entry : dp[i][j]) {
                int xor_val = entry.first;
                int count = entry.second;


                if (i + 1 < m) {
                    int next_xor = xor_val ^ grid[i + 1][j];
                    dp[i + 1][j][next_xor] = (dp[i + 1][j][next_xor] + count) % MOD;
                }


                if (j + 1 < n) {
                    int next_xor = xor_val ^ grid[i][j + 1];
                    dp[i][j + 1][next_xor] = (dp[i][j + 1][next_xor] + count) % MOD;
                }
            }
        }
    }


    return dp[m - 1][n - 1].count(k) ? dp[m - 1][n - 1][k] : 0;
}

int main() {
  
    return 0;
}
