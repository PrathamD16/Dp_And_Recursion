#include <bits/stdc++.h>
using namespace std;

// Recursion
int solve1(int row, int col, vector<vector<int>> &grid)
{
    if (row >= 0 && col >= 0 && grid[row][col] == -1)
        return 0;
    if (row == 0 && col == 0)
        return 1;
    if (row < 0 || col < 0)
        return 0;

    // We can only move up or left, if we start from bottom most right corner
    int up = solve1(row - 1, col, grid);
    int left = solve1(row, col - 1, grid);
    return up + left;
}

// Memoization
int solve2(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &dp)
{
    if (row >= 0 && col >= 0 && grid[row][col] == -1)
        return 0;
    if (row == 0 && col == 0)
        return 1;
    if (row < 0 || col < 0)
        return 0;

    // We can only move up or left, if we start from bottom most right corner
    if (dp[row][col] != -1)
        return dp[row][col];
    int up = solve1(row - 1, col, grid);
    int left = solve1(row, col - 1, grid);
    return dp[row][col] = up + left;
}

// Tabulation
int solve3(int row, int col, vector<vector<int>> &grid)
{
    vector<vector<int>> dp(row + 1, vector<int>(col + 1, 0));
    for (int i = 0; i <= row; i++)
    {
        for (int j = 0; j <= col; j++)
        {
            if (grid[i][j] == -1)
            {
                dp[i][j] = 0;
                continue;
            }
            if (i == 0 && j == 0)
            {
                dp[i][j] = 1;
                continue;
            }
            else
            {
                int right = 0, down = 0;
                if (i > 0)
                {
                    down = dp[i - 1][j];
                }
                if (j > 0)
                {
                    right = dp[i][j - 1];
                }
                dp[i][j] = down + right;
            }
        }
    }

    return dp[row][col];
}

// Main Function call
int getUniquePaths(vector<vector<int>> grid)
{
    int row = grid.size() - 1;
    int col = grid[0].size() - 1;
    vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), -1));
    // return solve1(row, col, grid);
    // return solve2(row, col, grid, dp);
    return solve3(row, col, grid);
}
int main()
{
    vector<vector<int>> grid = {{0, 0, 0}, {0, -1, 0}, {0, 0, 0}};
    cout << getUniquePaths(grid);
    return 0;
}
