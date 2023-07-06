#include <bits/stdc++.h>
using namespace std;

//Edit Distance
//Given 2 strings 's1' and 's2'. Find minimum numbers of operations to convert string 's1' to 's2'. You can do only 3 operations 'INSERT', 'DELETE' and 'REPLACE'.

void print(vector<vector<int>>mat){
    for(int i = 0; i < mat.size(); i++){
        for(int j = 0; j < mat[0].size(); j++){
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

int f1(int i, int j, string s1, string s2, vector<vector<int>>&dp){
    //base condition
    if(i == 0)return j;
    if(j == 0)return i;
    //choices
    if(dp[i][j] != -1)return dp[i][j];
    if(s1[i-1] == s2[j-1]){
        return dp[i][j] = 0 + f1(i-1, j-1, s1, s2, dp);
    }
    else{
        return dp[i][j] = 1 + min(f1(i, j-1, s1, s2, dp), min(f1(i-1, j, s1, s2, dp), f1(i-1, j-1, s1, s2, dp)));
    }
}

int f2(string s1, string s2){
    int l1 = s1.size();
    int l2 = s2.size();
    vector<vector<int>>dp(l1+1, vector<int>(l2+1, 0));
    for(int j = 0; j <= l2; j++){
        dp[0][j] = j;
    }
    for(int i = 0; i <= l1; i++){
        dp[i][0] = i;
    }

    for(int i = 1; i <= l1; i++){
        for(int j = 1; j <= l2; j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = 0 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = 1 + min(dp[i][j-1], min(dp[i-1][j], dp[i-1][j-1]));
            }
        }
    }
    print(dp);
    return dp[l1][l2];
}

int main(){
    string s1 = "horse";
    string s2 = "ros";
    int l1 = s1.size();
    int l2 = s2.size();
    vector<vector<int>>dp(l1+1, vector<int>(l2+1, -1));
    // cout << f1(l1, l2, s1, s2, dp);
    // cout << f2(s1, s2);
    f2(s1, s2);
    return 0;
}