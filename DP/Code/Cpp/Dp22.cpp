#include <bits/stdc++.h>
using namespace std;

//Given array of 'coins' where 'coins[i]' represent each distinct coins, and a 'target'. You have infinite supply of coins.
//You have to pick the coins and match the target value. 
// Return number of ways in which you can reach the target.

//Recursion approach
int f1(int index, int target, vector<int>&coins, vector<vector<int>>dp){
    if(index == 0){
        if(target%coins[0] == 0)return 1;
        return 0;
    }
    if(dp[index][target] != -1)return dp[index][target];
    int not_pick = f1(index-1, target, coins, dp);
    int pick = 0;
    if(coins[index] <= target){
        pick = f1(index, target-coins[index], coins, dp);
    }
    return dp[index][target] = not_pick + pick;
}

//Tabulation approach
int f2(vector<int>&coins, int target){
    int n = coins.size();
    vector<vector<int>>dp(n, vector<int>(target+1, 0));
    for(int T = 0; T <= target; T++){
        if(T%coins[0] == 0)dp[0][T] = 1;
    }

    for(int ind = 1; ind < n; ind++){
        for(int T = 0; T <= target; T++){
            int not_pick = dp[ind-1][T];
            int pick = 0;
            if(coins[ind] <= T){
                pick = dp[ind][T-coins[ind]];
            }
            dp[ind][T] = not_pick + pick;
        }
    }

    return dp[n-1][target];

}


int main(){
    vector<int>coins = {1,2,3};
    int target = 4;
    int n = coins.size();
    vector<vector<int>>dp(n, vector<int>(target+1, -1));
    // cout << f1(n-1, target, coins, dp);
    cout << f2(coins, target);
    return 0;
}