#include <bits/stdc++.h>
using namespace std;

// You are given a triangle (pascals triangle). Find the minimum path from top to bottom, where we can only move to (i+1) element or (i+1)(j+1)element Only diagonal movement is allowed.

// Recursion Approach
int solve1(vector<vector<int>> &grid, int row, int col)
{
    if (row == grid.size() - 1)
        return grid[grid.size() - 1][col];

    int down = grid[row][col] + solve1(grid, row + 1, col);
    int diagonal = grid[row][col] + solve1(grid, row + 1, col + 1);
    return min(down, diagonal);
}

// Memoization
int solve2(vector<vector<int>> &grid, int row, int col, vector<vector<int>> &dp)
{
    if (row == grid.size() - 1)
        return grid[grid.size() - 1][col];
    if (dp[row][col] != -1)
        return dp[row][col];
    int down = grid[row][col] + solve1(grid, row + 1, col);
    int diagonal = grid[row][col] + solve1(grid, row + 1, col + 1);
    return dp[row][col] = min(down, diagonal);
}

//TopDown Approach (Tabulation)
int solve3(vector<vector<int>>&grid){
    int n = grid.size();
    vector<vector<int>>dp(n, vector<int>(n,-1));
    for(int j = 0; j < n; j++){
        dp[n-1][j] = grid[n-1][j];
    }

    for(int i = n - 2; i >= 0; i--){
        for(int j = i; j >= 0; j--){
            int down = grid[i][j] + dp[i+1][j];
            int dg = grid[i][j] + dp[i+1][j+1];
            dp[i][j] = min(down,dg);
        }
    }

    return dp[0][0];

}

int findMinPath(vector<vector<int>> &grid)
{
    vector<vector<int>>dp(grid.size(), vector<int>(grid.size(),-1));
    // return solve1(grid, 0, 0);
    // return solve2(grid,0,0,dp);
    return solve3(grid);
    
}

int main()
{

    vector<vector<int>> grid = {{1}, {2, 3}, {3, 6, 7}, {8, 9, 6, 10}};
    cout << findMinPath(grid);

    return 0;
}