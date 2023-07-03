#include <bits/stdc++.h>
using namespace std;

// There is array of 'weight' and 'values'. 'weight' array contains some objects and each weight of an object is represented by weight[i] and it's value is represented by 'values[i]'. You are given a bag of weight 'W'. Your task is to objects into the BAG such that you can maxmimize your profit. Consider infinite supply of objects and it's value.

int f1(int ind, vector<int>&wt, vector<int>&val, int W, vector<vector<int>>dp){
    if(ind == 0){
        if(wt[0] <= W){
            return (W/wt[0])*val[0];
        }
        return 0;
    }

    if(dp[ind][W] != -1)return dp[ind][W];

    int not_pick = 0 + f1(ind-1, wt, val, W, dp);
    int pick = -1e9;
    if(wt[ind] <= W){
        pick = val[ind] + f1(ind, wt, val, W-wt[ind], dp);
    }
    return dp[ind][W] = max(not_pick, pick);
}

//Tabulation
int f2(vector<int>&wt, vector<int>&val, int W){
    int n = val.size();
    vector<vector<int>>dp(n, vector<int>(W+1, 0));

    for(int w = 0; w <= W; w++){
        if(wt[0] <= w){
            dp[0][w] = (w/wt[0])*val[0];
        }
    }

    for(int ind = 1; ind < n; ind++){
        for(int w = 0; w <= W; w++){
            int notPick = 0 + dp[ind-1][w];
            int pick = -1e9;
            if(wt[ind] <= w){
                pick = val[ind] + dp[ind][w-wt[ind]];
            }

            dp[ind][w] = max(notPick, pick);
        }
    }

    return dp[n-1][W];
}

//Space optimized
int f3(vector<int>&wt, vector<int>&val, int W){
    int n = val.size();
    vector<int>curr(W+1, 0);
    vector<int>pre(W+1, 0);

    for(int w = 0; w <= W; w++){
        if(wt[0] <= w){
            pre[w] = (w/wt[0])*val[0];
        }
    }

    for(int ind = 1; ind < n; ind++){
        for(int w = 0; w <= W; w++){
            int notPick = 0 + pre[w];
            int pick = -1e9;
            if(wt[ind] <= w){
                pick = val[ind] + curr[w-wt[ind]];
            }

            curr[w] = max(notPick, pick);
        }

        pre = curr;
    }

    return pre[W];
}

int main(){
    vector<int>wt = {2, 4, 6};
    vector<int>val = {5, 11, 13};
    int W = 10;
    int n = wt.size();

    vector<vector<int>>dp(n, vector<int>(W+1, -1));

    // cout << f1(n-1, wt, val, W, dp);
    // cout << f2(wt, val, W);
    // cout << f3(wt, val, W);
    return 0;
}