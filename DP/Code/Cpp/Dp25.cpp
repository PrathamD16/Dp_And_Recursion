#include <bits/stdc++.h>
using namespace std;
//***DP ON STRING
//Longest common sub-sequences

//Recursion approach
int f1(int i1, int i2, string s1, string s2, vector<vector<int>>dp){
    if(i1 ==  0 || i2 == 0){
        return 0;
    }
    
    if(dp[i1][i2] != -1)return dp[i1][i2];

    if(s1[i1-1] == s2[i2-1]){
        return dp[i1][i2] = 1 + f1(i1-1, i2-1, s1, s2, dp);
    }

    return dp[i1][i2] =  0 + max(f1(i1-1, i2, s1, s2, dp),f1(i1, i2-1, s1, s2, dp));
}

//Tabulation approach
int f2(string s1, string s2){
    int n1 = s1.length();
    int n2 = s2.length();
    vector<vector<int>>dp(n1+1, vector<int>(n2+1, 0));
    
    for(int i = 1; i <= n1; i++){
        for(int j = 1; j <= n2; j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
                continue;
            }
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    
    return dp[n1][n2];
}

int main(){

    string s1 = "adcbc";
    string s2 = "dcadb";
    int n1 = s1.length();
    int n2 = s2.length();
    vector<vector<int>>dp(n1+1, vector<int>(n2+1, -1));
    // cout << f1(n1, n2, s1, s2, dp);
    cout << f2(s1, s2);
    return 0;
}