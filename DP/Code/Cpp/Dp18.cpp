#include <bits/stdc++.h>
using namespace std;

// #Count Paritition with given difference

int f1(int ind, vector<int>&nums, int target, vector<vector<int>>&dp){
    //If number in array contains numbers greater than equal to 0
    if(ind == 0){
        if(target == 0 && nums[0] == 0)return 2;
        else if(target == 0 || target == nums[0])return 1;
        return 0;
    }

    //Constrains:-> if numbers in arrays are all greater than 0
    // if(target == 0)return 1;
    // if(ind == 0){
    //     if(target == nums[0])return 1;
    //     return 0;
    // }

    if(dp[ind][target] != -1)return dp[ind][target];
    int not_pick = f1(ind-1, nums, target, dp);
    int pick = 0;
    if(nums[ind] <= target){
        pick = f1(ind-1, nums, target-nums[ind], dp);
    }

    return dp[ind][target] = not_pick + pick;
}

int tabulation(vector<int>&nums, int target){
    int n = nums.size();
    vector<vector<int>>dp(n, vector<int>(target+1, 0));
    
    if(nums[0] == 0)dp[0][0] = 2;
    else dp[0][0] = 1;


    if(nums[0] <= target && nums[0] != 0)dp[0][nums[0]] = 1;
    for(int ind = 1; ind < n; ind++){
        for(int sum = 0; sum <= target; sum++){
            int not_take = dp[ind-1][sum];
            int take = 0;
            if(nums[ind] <= sum){
                take = dp[ind-1][sum-nums[ind]];
            }

            dp[ind][sum] = take + not_take;
        }
    }

    return dp[n-1][target];
}

int countParition(vector<int>&nums, int d){
    int sum = 0;
    int n = nums.size()-1;
    for(int i = 0; i < nums.size(); i++){   
        sum += nums[i];
    }

    int target = (sum - d)/2;
    vector<vector<int>>dp(nums.size(), vector<int>(target+1, -1));
    // return f1(n, nums, target, dp);
    return tabulation(nums, target);
}

int main()
{
    vector<int> nums = {5, 2, 6, 4};
    cout << countParition(nums, 3);
    return 0;
}