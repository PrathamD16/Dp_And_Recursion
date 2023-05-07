#include <bits/stdc++.h>
using namespace std;

int f1(int row, int col, vector<vector<int>> &triangle, int s, vector<vector<int>>&dp)
{
    if (row >= s || col < 0 || col >= triangle[row].size())
        return 0;
    if (row == s - 1)
    {
        if (col >= 0 && col < triangle[0].size())
            return triangle[row][col];
    }

    if(dp[row][col] != -1)return dp[row][col];
    int left = triangle[row][col] + f1(row + 1, col, triangle, s, dp);
    int right = triangle[row][col] + f1(row + 1, col + 1, triangle, s, dp);
    return min(left, right);
}

int minimumTotal(vector<vector<int>> &triangle)
{
    int s = triangle.size();
    vector<vector<int>>dp(s, vector<int>(s, -1));
    return f1(0, 0, triangle, s, dp);
}

int main()
{
    vector<vector<int>> triangle = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    cout << minimumTotal(triangle);
    return 0;
}