#include <bits/stdc++.h>
using namespace std;
// Given M*N matrix with integer number. Find maximum sum obtain starting from any column in first row and ending at any column in last row.
// Allowed move:
// Down(row+1, col) DownLeft_Diagonal(row+1, col-1) DownRight_Diagonal(row+1, col+1)


//Recursion
int solve1(int i, int j, vector<vector<int>>&grid){
    if(j < 0 || j > 0)return -1e9;
    if(i == 0)return grid[0][j];
    int s = grid[i][j] + solve1(i-1,j,grid);
    int ld = grid[i][j] + solve1(i-1,j-1,grid);
    int rd = grid[i][j] + solve1(i-1,j+1,grid);
    return max(s,max(ld,rd));
}

int maxSumPath(vector<vector<int>>&grid){
    int row = grid.size();
    int cost = -1e9;
    int col = grid[0].size();

    //As we can start from any column, so trying out all possible path
    for(int j = 0; j < col; j++){
        int pathCost = solve1(row-1,j,grid);
        if(pathCost > cost){
            cost = pathCost;
        }
    }
    return cost;
}

int main()
{
    vector<vector<int>> grid = {{1, 2, 10, 4}, {100, 3, 2, 1}, {1, 1, 20, 2}, {1, 2, 2, 1}};
    cout << maxSumPath(grid);
    return 0;
}