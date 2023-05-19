#include <bits/stdc++.h>
using namespace std;

int f1(int ind, vector<int>&nums, int target, vector<vector<int>>&dp){
    if(target == 0)return 1;
    if(ind == 0){
        if(target == nums[0])return 1;
        return 0;
    }

    if(dp[ind][target] != -1)return dp[ind][target];
    int not_pick = f1(ind-1, nums, target, dp);
    int pick = 0;
    if(nums[ind] <= target){
        pick = f1(ind-1, nums, target-nums[ind], dp);
    }

    return dp[ind][target] = not_pick + pick;
}

int countSubsets(vector<int>&nums, int target){
    int n = nums.size();
    vector<vector<int>>dp(n, vector<int>(target+1, -1));
    return f1(n-1, nums, target, dp);

}

int tabulation(vector<int>&nums, int target){
    int n = nums.size();
    vector<vector<int>>dp(n, vector<int>(target+1, 0));
    for(int ind = 0; ind < n; ind++){
        dp[ind][0] = 1;
    }

    if(nums[0] <= target)dp[0][nums[0]] = 1;
    for(int ind = 1; ind < n; ind++){
        for(int sum = 0; sum <= target; sum++){
            int not_take = dp[ind-1][sum];
            int take = 0;
            if(nums[ind] <= sum){
                take = dp[ind-1][target-nums[ind]];
            }

            dp[ind][sum] = take + not_take;
        }
    }

    return dp[n-1][target];
}

int main(){
    vector<int>nums = {1,2,2,3}    ;
    int target = 3;
    cout << countSubsets(nums,3);
    cout << tabulation(nums,3);
    return 0;
}