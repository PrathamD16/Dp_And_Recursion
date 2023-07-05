#include <bits/stdc++.h>
using namespace std;

//Minimum number of possible operation to make string1 equal to string 2

//Approach

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

    return (n1 + n2) - (2 * dp[n1][n2]);
}

int main(){
    string s1 = "abcd";
    string s2 = "anc";
    cout << f2(s1, s2);
    return 0;
}