#include <bits/stdc++.h>
using namespace std;

// Rod cutting problem
// Given length of the rod 'n'. Cut the rod into pieces such that cost obtained is maximum by selling the cutted rod. Given a array of 'cost' starting from INDEX 1, the INDEX represent the length of cutted piece and cost[i] represent the cost of the respective length.
// 0 <= cost.length < N;

// Recursion
// Try to pick lengths and sum till 'N' and find the maximum cost
int f1(int ind, vector<int> &cost, int N, vector<vector<int>>dp)
{
    if(ind == 0){
        return N*cost[0];
    }

    if(dp[ind][N] != -1)return dp[ind][N];
    
    int not_pick = f1(ind - 1, cost, N, dp);
    int pick = INT_MIN;
    int rod_length = ind + 1;
    if (rod_length <= N)
    {
        pick = cost[ind] + f1(ind, cost, N - rod_length, dp);
    }
    return dp[ind][N] = max(not_pick, pick);
}

//Tabulation
int f2(int N, vector<int>&cost){
    vector<vector<int>>dp(N, vector<int>(N+1, 0));
    for(int L = 0; L <= N; L++){
        dp[0][L] = L*cost[0];
    }

    for(int ind = 1; ind < N; ind++){
        for(int L = 0; L <= N; L++){
            int not_pick = 0 + dp[ind-1][L];
            int pick = INT_MIN;
            int rodLength = ind + 1;
            if(rodLength <= L){
                pick = cost[ind] + dp[ind][L-rodLength];
            }

            dp[ind][L] = max(not_pick, pick);
        }
    }

    return dp[N-1][N];
}

int main()
{
    int N = 5;
    vector<int> cost = {2, 5, 7, 8, 10};
    vector<vector<int>>dp(N, vector<int>(N+1, -1));
    // cout << f1(N-1, cost, N, dp);
    cout << f2(N, cost);
    return 0;
}