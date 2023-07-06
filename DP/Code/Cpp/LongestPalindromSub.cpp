#include <bits/stdc++.h>
using namespace std;

//length of longest substring
bool isPalindrome(string s, int i, int j){
    while(i <= j){
        if(s[i] != s[j])return false;
        i++;
        j--;
    }
    return true;
}

int f1(string s, int i, int j){
    //base condition
    if(i >= j)return 1;
    //choice;
    if(isPalindrome(s, i, j)){
        return j-i+1;
    }
    return max(f1(s,i+1,j), f1(s,i,j-1));
}

int f2(string s){
    int n = s.size();
    vector<vector<int>>dp(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j){
                dp[i][j] = 1;
            }
        }
    }

    int Max = 1;
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = n-1; j >= Max; j--){
            if(isPalindrome(s,i,j)){
                dp[i][j] = j - i + 1;
                ans = max(ans, dp[i][j]);
            }
            else{
                dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
            }
        }
        Max++;
    }

    return ans;
}

int main(){
    // string s = "aaaabbaa";
    string s = "abababaaaa";
    int n = s.size();
    // cout << f1(s, 0, n - 1);
    cout << f2(s);
    return 0;
}