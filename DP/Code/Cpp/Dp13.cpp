#include <bits/stdc++.h>
using namespace std;
// Problem: There is a 2D grid of size MxN and there are two ninjas, at position 0,0 and 0,N-1
// Find maximum fruit the can collect to react M-1 row. If both of them intersect at same place, Consider the fruit collected only once and finally sum both of the collected fruit and return maximum.
int f1(int i, int j1, int j2, int r, int c, vector<vector<int>>&grid,vector<vector<vector<int>>>&dp){
    if(j1 < 0 || j2 < 0 || j1 >= c || j2 >= c){
        return -1e8;
    }
    if(i == r - 1){
        if(j1 == j2)return grid[i][j1];
        else return grid[i][j1] + grid[i][j2];
    }

    if(dp[i][j1][j2] != -1)return dp[i][j1][j2];

    int maxi = -1e8;
    for(int dj1 = -1; dj1 < 2; dj1++){
        for(int dj2 = -1; dj2 < 2; dj2++){
            int value = 0;
            if(j1 == j2)value = grid[i][j2];
            else{
                value = grid[i][j1] + grid[i][j2];
            }
            value += f1(i+1,j1+dj1, j2+dj2, r, c, grid, dp);
            maxi = max(maxi, value);
        }
    }
    return dp[i][j1][j2] = maxi;

}

int getMaxPath(vector<vector<int>> &grid)
{
    int r = grid.size();
    int c = grid[0].size();
    vector<vector<vector<int>>>dp(r, vector<vector<int>>(c, vector<int>(c, -1)));
    return f1(0,0,c-1,r,c,grid,dp);
}

int main()
{
    vector<vector<int>> grid = {{2, 3, 1, 2}, {3, 4, 2, 2}, {5, 6, 3, 5}};
    cout << getMaxPath(grid);
    return 0;
}