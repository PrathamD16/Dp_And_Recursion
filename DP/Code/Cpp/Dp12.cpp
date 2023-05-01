#include <bits/stdc++.h>
using namespace std;
// Given M*N matrix with integer number. Find maximum sum obtain starting from any column in first row and ending at any column in last row.
// Allowed move:
// Down(row+1, col) DownLeft_Diagonal(row+1, col-1) DownRight_Diagonal(row+1, col+1)


//Recursion
int solve1(int i, int j, vector<vector<int>>&grid){
    if(j < 0 || j > grid[0].size())return -1e9;
    if(i == 0)return grid[0][j];
    int s = grid[i][j] + solve1(i-1,j,grid);
    int ld = grid[i][j] + solve1(i-1,j-1,grid);
    int rd = grid[i][j] + solve1(i-1,j+1,grid);
    return max(s,max(ld,rd));
}

//Memoization
int solve2(int i, int j, vector<vector<int>>&grid, vector<vector<int>>&dp){
    if(j < 0 || j > grid[0].size())return -1e9;
    if(i == 0)return grid[0][j];
    if(dp[i][j] != -1)return dp[i][j];
    int s = grid[i][j] + solve2(i-1,j,grid, dp);
    int ld = grid[i][j] + solve2(i-1,j-1,grid, dp);
    int rd = grid[i][j] + solve2(i-1,j+1,grid, dp);
    return dp[i][j] = max(s,max(ld,rd));
}

//Tabulation form
void solve3(vector<vector<int>>&grid, vector<vector<int>>&dp){
    //Tabulation Form;
    int row = grid.size();
    int col = grid[0].size();
    for(int j = 0; j < col; j++){
        dp[0][j] = grid[0][j];
    }

    for(int i = 1; i < row; i++){
        for(int j = 0; j < col; j++){
            int s = grid[i][j];
            int ld = grid[i][j];
            int rd = grid[i][j];
            s += dp[i-1][j];
            if(j-1 >= 0){
                ld += dp[i-1][j-1];
            }
            else ld += -1e8;
            if(j+1 < col){
                rd += dp[i-1][j+1];
            }
            else rd += -1e8;

            dp[i][j] = max(s,max(ld,rd));
        }   
    }
}

int maxSumPath(vector<vector<int>>&grid){
    int row = grid.size();
    int cost = -1e9;
    int col = grid[0].size();
    vector<vector<int>>dp(row, vector<int>(col, 0));

    //Recursion
    // for(int j = 0; j < col; j++){   
    //     cost = max(cost, solve1(row-1, j, grid));
    // }

    //Tabulation
    solve3(grid, dp);
    for(int i = 0; i < col; i++){
        cost = max(cost, dp[row-1][i]);
    }

    return cost;
}

int main()
{
    vector<vector<int>> grid = {{1, 2, 10, 4}, {100, 3, 2, 1}, {1, 1, 20, 2}, {1, 2, 2, 1}};
    cout << maxSumPath(grid);
    
    return 0;
}