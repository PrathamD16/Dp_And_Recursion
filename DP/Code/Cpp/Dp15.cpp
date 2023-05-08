#include <bits/stdc++.h>
using namespace std;
bool tabulation(vector<int> &arr, int target)
{
    int n = arr.size();
    vector<vector<bool>> dp(arr.size(), vector<bool>(target + 1, false));
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = true;
    }

    dp[0][arr[0]] = true;

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= target; j++)
        {
            bool notTake = dp[i - 1][j];
            bool take = false;
            if (arr[i] <= j)
            {
                take = dp[i - 1][j - arr[i]];
            }
            dp[i][j] = notTake | take;
        }
    }

    return dp[n - 1][target];
}
bool canPartition(vector<int> &arr)
{
    int n = arr.size();
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    vector<int>dp(n, -1);
    if (sum % 2)
        return false;
    else
    {
        int target = sum / 2;
        vector<int>dp(n, -1);
        return tabulation(arr,target);
    }
}

int main()
{
    vector<int> arr = {2, 3, 3, 3, 5, 4};
    cout << canPartition(arr);
    return 0;
}