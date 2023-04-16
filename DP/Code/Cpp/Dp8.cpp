#include <bits/stdc++.h>
using namespace std;
// Unique Paths in a grid starting from leftmost upper corner and ending at rightmost bottom corner
// Here only size of matrix will be given in form MxN.

// Recursion Approach
int solve1(int row, int col)
{
    if (row < 0 || col < 0)
        return 0;
    if (row == 0 && col == 0)
        return 1;

    // We can only move up or left, if we start from bottom most right corner
    int up = solve1(row - 1, col);
    int left = solve1(row, col - 1);
    ;
    return up + left;
}

// Memoization
int solve2(int row, int col, vector<vector<int>> dp)
{
    if (row < 0 || col < 0)
        return 0;
    if (row == 0 && col == 0)
        return 1;

    if(dp[row][col] != -1)return dp[row][col];
    int up = solve1(row - 1, col);
    int left = solve1(row, col - 1);
    return dp[row][col] = up + left;
}

//Memoization
int solve3(int row, int col, vector<vector<int>>dp){
    dp[0][0] = 1;
    for(int i = 0; i <= row; i++){
        for(int j = 0; j <= col; j++){
            int down = 0, right = 0;
            if(i == 0 && j == 0){
                dp[0][0] = 1;
                continue;
            };
            if(i > 0){
                down = dp[i-1][j];
            }
            if(j > 0){
                right = dp[i][j-1];
            }
            dp[i][j] = down + right;
        }
    }
    return dp[row][col];
}

int numberOfUniquePaths(int row, int col)
{
    vector<vector<int>>dp(row,vector<int>(col, -1));
    // return solve1(row - 1, col - 1);
    // return solve2(row-1,col-1,dp);
    return solve3(row-1,col-1,dp);
}

int main()
{

    cout << numberOfUniquePaths(10,10) << endl;
    return 0;
}