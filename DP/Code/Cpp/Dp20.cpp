#include <bits/stdc++.h>
using namespace std;

// Minimum coins
// problem given arrays of coins, required to match target value, you can take coins as many time as you want, return minimum numbers of coins

// Recursion approach
int f1(int ind, vector<int> arr, int target, vector<vector<int>> dp)
{
    if (ind == 0)
    {
        if (target % arr[ind] == 0)
            return target / arr[ind];
        return 1e9;
    }
    int pick = INT_MAX;
    if (dp[ind][target] != -1)
        return dp[ind][target];
    if (target >= arr[ind])
    {
        pick = 1 + f1(ind, arr, target - arr[ind], dp);
    }
    int not_pick = 0 + f1(ind - 1, arr, target, dp);
    return dp[ind][target] = min(pick, not_pick);
}

//tabulation approach
int f2(vector<int>arr, int target){
    int n = arr.size();
    vector<vector<int>>dp(n, vector<int>(target+1, 0));
    //For space optimization
    vector<int>pre(target+1, 0);
    vector<int>curr(target+1, 0);

    for(int T = 0; T <= target; T++){
        if(T%arr[0] == 0){
            // dp[0][T] = T/arr[0];
            pre[T] = T/arr[0];
        }
        else {
            // dp[0][T] = 1e9;
            pre[T] = 1e9;
        }
    }

    for(int ind = 1; ind < n; ind++){
        for(int T = 0; T <= target; T++){
            // int not_take = 0 + dp[ind-1][T];
            int not_take = 0 + pre[T];
            int take = INT_MAX;
            if(arr[ind] <= T){
                // take = 1 + dp[ind][T - arr[ind]];
                take = 1 + curr[T - arr[ind]];
            }

            // dp[ind][T] = min(not_take, take);
            curr[T] = min(take, not_take);
        }
        pre = curr;
    }

    // return dp[n-1][target];
    return curr[target];


}

int main()
{
    vector<int> arr = {1, 2, 3};
    int target = 10;
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(target + 1, -1));
    // cout << f1(n - 1, arr, target, dp);
    cout << f2(arr, target);
    return 0;
}