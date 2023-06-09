#include <bits/stdc++.h>
using namespace std;

//Distinct subsquence
//Given 2 strings 's1' and 's2'. Find number of occurence of 's2' in 's1'

int f1(int i, int j, string s1, string s2, vector<vector<int>>dp){
    //base conditions
    if(j == 0)return 1;
    if(i == 0)return 0;
    if(dp[i][j] != -1)return dp[i][j];
    if(s1[i-1] == s2[j-1]){
        //1. 1st call determine when both are matched we shrink both the string
        //2. 2nd call determine that there can be another possibility in s1.
        return dp[i][j] = f1(i-1, j-1, s1, s2, dp) + f1(i-1, j, s1, s2, dp);
    }
    else{
        //When there is no match, s1 shrinks
        return dp[i][j] = f1(i-1, j, s1, s2, dp);
    }
}

int f2(string s1, string s2){
    int n1 = s1.length();
    int n2 = s2.length();
    vector<vector<int>>dp(n1+1, vector<int>(n2+1, 0)); 

    //base condition
    for(int i = 0; i <= n1; i++){
        dp[i][0] = 1;
    }
    
    for(int i = 1; i <= n1; i++){
        for(int j = 1; j <= n2; j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n1][n2];
    
}

int main(){
    string s1 = "babgbag";
    string s2 = "bag";
    int n1 = s1.length();
    int n2 = s2.length();
    vector<vector<int>>dp(n1+1, vector<int>(n2+1, -1));
    // cout << f1(n1, n2, s1, s2, dp);  
    cout << f2(s1, s2);
    return 0;
}