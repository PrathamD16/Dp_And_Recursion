#include <bits/stdc++.h>
using namespace std;
// Subset sum problem: Given an array of n integer. There exists subset whose sum is equal to K

bool f1(int ind, int target, vector<int> &arr, vector<vector<int>>&dp)
{
    if (target == 0)
        return true;
    if (ind == 0)
    {
        return arr[0] == target;
    }

    if(dp[ind][target] != -1)return dp[ind][target];
    bool notTake = f1(ind - 1, target, arr, dp);
    bool take = false;
    if (arr[ind] <= target)
    {
        take = f1(ind - 1, target - arr[ind], arr, dp);
    }

    return dp[ind][target] = notTake | take;
}

bool tabulation(vector<int>&arr, int target){
    int n = arr.size();
    vector<vector<bool>>dp(arr.size(), vector<bool>(target+1, false));
    for(int i = 0; i < n; i++){
        dp[i][0] = true;
    }

    dp[0][arr[0]] = true;

    for(int i = 1; i < n; i++){
        for(int j = 1; j <= target; j++){
            bool notTake = dp[i-1][j];
            bool take = false;
            if(arr[i] <= j){
                take = dp[i-1][j-arr[i]];
            }
            dp[i][j] = notTake | take;
        }
    }

    return dp[n-1][target];

}

bool subsetExist(vector<int> &nums, int target)
{
    int s = nums.size();
    vector<vector<int>>dp(s+1, vector<int>(target+1, -1));
    return f1(s - 1, target, nums, dp);
    // return tabulation(nums,target);
}

int main()
{
    vector<int> nums = {1, 3, 4};
    cout << subsetExist(nums, 9);
    return 0;
}