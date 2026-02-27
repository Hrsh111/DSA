/*
 * LeetCode #200 - Number of Islands
 * https://leetcode.com/problems/number-of-islands/
 *
 * Given an m x n 2D binary grid grid which represents a map of '1's (land) and
 * '0's (water), return the number of islands.
 *
 * An island is surrounded by water and is formed by connecting adjacent lands
 * horizontally or vertically. You may assume all four edges of the grid are all
 * surrounded by water.
 *
 * Example 1:
 * Input: grid = [
 *   ["1","1","1","1","0"],
 *   ["1","1","0","1","0"],
 *   ["1","1","0","0","0"],
 *   ["0","0","0","0","0"]
 * ]
 * Output: 1
 *
 * Example 2:
 * Input: grid = [
 *   ["1","1","0","0","0"],
 *   ["1","1","0","0","0"],   [2,2]-> for going up reduce the row [2-1,2]
 *   ["0","0","1","0","0"],   [2,2]-> down increase the the row [2+1,2] 
 *   ["0","0","0","1","1"]    [2,2]-> for going left reduce the column[row, col-1]   
 * ]                          [2,2]-> for going right increase the column  [row,col+1]
 * 
 * Output: 3
 *
 * Constraints:
 * - m == grid.length
 * - n == grid[i].length
 * - 1 <= m, n <= 300
 * - grid[i][j] is '0' or '1'.
 * 
 * 
 * 
 * grid=
 * ["(row, col)", "(row,col+1)"],
 * ["(row+1,col)","(row+1,col+1)"]
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
void dfs(vector<vector<char>>&grid, int row, int col){
    if(row<0 || row>=grid.size() || col<0 || col>=grid[0].size()|| grid[row][col]!='1')
        return;
        grid[row][col]='0';
    dfs(grid, row-1, col);//up 
    dfs(grid, row, col-1);//down
    dfs(grid, row, col+1);//right
    dfs(grid, row+1, col);//left
    
}
    int numIslands(vector<vector<char>>& grid) {
            int Islandcnt=0;
            int row= grid.size();
            int col= grid[0].size();
            for(int i=0;i<row;i++){
                for(int j=0;j<col;j++){
                if(grid[i][j]=='1'){
                    Islandcnt++;  
                    dfs(grid, i, j);
                }
            }
            }
            return Islandcnt;

    }
};

// Test cases
int main() {
    Solution sol;

    // Test case 1
    vector<vector<char>> grid1 = {
        {'1', '1', '1', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}
    };
    cout << "Test 1: " << sol.numIslands(grid1) << endl;
    // Expected: 1

    // Test case 2
    vector<vector<char>> grid2 = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };
    cout << "Test 2: " << sol.numIslands(grid2) << endl;
    // Expected: 3

    return 0;
}
