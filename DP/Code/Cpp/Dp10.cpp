#include <bits/stdc++.h>
using namespace std;
// Given grid of size MxN with values in each cell. Find path from 0,0 to M-1,N-1 such that cost is minimum

// Recursion
long solve1(int row, int col, vector<vector<int>> &grid)
{
    if (row == 0 && col == 0)
        return grid[0][0];
    if (row < 0 || col < 0)
        return INT_MAX;
    long left = grid[row][col] + solve1(row, col - 1, grid);
    long up = grid[row][col] + solve1(row - 1, col, grid);
    return min(left, up);
}

// Memoization
long solve2(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &dp)
{
    if (row == 0 && col == 0)
        return grid[0][0];
    if (row < 0 || col < 0)
        return INT_MAX;
    if (dp[row][col] != -1)
        return dp[row][col];
    long left = grid[row][col] + solve1(row, col - 1, grid);
    long up = grid[row][col] + solve1(row - 1, col, grid);
    return dp[row][col] = min(left, up);
}

// Tabulation part
int solve3(vector<vector<int>> &grid){
    int row = grid.size();
    int col = grid[0].size();
    vector<vector<int>>dp(row,vector<int>(col,0));
    dp[0][0] = grid[0][0];
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(i == 0 && j == 0){
                dp[i][j] = grid[i][j];
            }
            else{
                int left = grid[i][j];
                int up = grid[i][j];
                if(i > 0){
                    up += dp[i-1][j];
                }
                else{
                    up += 1e9;
                }
                if(j > 0){
                    left += dp[i][j-1];
                }
                else{
                    left += 1e9;
                }

                dp[i][j] = min(left,up);
            }
        }
    }

    return dp[row-1][col-1];
}


long minCostPath(vector<vector<int>> &grid)
{
    int row = grid.size() - 1;
    int col = grid[0].size() - 1;
    vector<vector<int>> dp(row + 1, vector<int>(col + 1, -1));
    // return solve1(row,col,grid);
    // return solve2(row,col,grid,dp);
    return solve3(grid);
}

int main()
{
    vector<vector<int>> grid = {{5, 9, 6}, {11, 5, 2}};
    cout << minCostPath(grid);
    return 0;
}
