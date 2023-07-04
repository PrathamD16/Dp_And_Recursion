#include <bits/stdc++.h>
using namespace std;

//Longest common substring

//intution: similar to LCS, we write same approach for substring, but if matrix to maintain the consecutiveness of a substring we refer diagonal of a matrix.

int f1(string s1, string s2){
    int l1 = s1.length();
    int l2 = s2.length();
    vector<vector<int>>dp(l1+1, vector<int>(l2+1, 0));

    int ans = 0;
    for(int i = 1; i <= l1; i++){
        for(int j = 1; j <= l2; j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
                ans = max(ans, dp[i][j]);
            }
        }
    }

    return ans;
}

int main(){
    string s1 = "abcjklp";
    string s2 = "acjkp";
    cout << f1(s1, s2);
    return 0;
}