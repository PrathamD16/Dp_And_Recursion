#include <bits/stdc++.h>
using namespace std;

// 0-1 KnapSack
// Recursion
int f1(int ind, vector<int> &wt, vector<int> &val, int bagWt, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        if (wt[0] <= bagWt)
            return val[0];
        return 0;
    }
    int take = INT_MIN;
    if (dp[ind][bagWt] != -1)
        return dp[ind][bagWt];
    if (wt[ind] <= bagWt)
    {
        take = val[ind] + f1(ind - 1, wt, val, bagWt - wt[ind], dp);
    }
    int not_take = 0 + f1(ind - 1, wt, val, bagWt, dp);
    return dp[ind][bagWt] = max(take, not_take);
}

// Tabulation method
int tabulation(vector<int> &wt, vector<int> &val, int bagWt)
{
    int n = wt.size();
    vector<vector<int>> dp(n, vector<int>(bagWt + 1, 0));
    for (int j = 0; j <= bagWt; j++)
    {
        if(wt[0] <= j){
            dp[0][j] = val[0];
        }
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= bagWt; j++)
        {
            int take = INT_MIN;
            if (wt[i] <= j)
            {
                take = val[i] + dp[i - 1][j - wt[i]];
            }
            int not_take = 0 + dp[i - 1][j];
            dp[i][j] = max(take, not_take);
        }
    }

    return dp[n - 1][bagWt];
}

int stealItem(vector<int> &wt, vector<int> &val, int bagWt)
{
    int n = wt.size();
    vector<vector<int>> dp(n, vector<int>(bagWt + 1, -1));
    // return f1(n - 1, wt, val, bagWt, dp);
    return tabulation(wt, val, bagWt);
}

int main()
{

    vector<int> wt = {3, 2, 5};
    vector<int> val = {30, 40, 60};
    cout << stealItem(wt, val, 6);

    return 0;
}