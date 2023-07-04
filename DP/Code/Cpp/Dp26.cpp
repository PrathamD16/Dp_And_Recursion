#include <bits/stdc++.h>
using namespace std;

//Print the longest common subsequence string
string f2(string s1, string s2){
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

    int i = n1, j = n2;
    int index = dp[n1][n2];
    string ans = "";
    while(i > 0 && j > 0){
        if(s1[i-1] == s2[j-1]){
            ans += s1[i-1];
            i--;
            j--;
        }
        else if(dp[i-1][j] > dp[i][j-1])i--;
        else j--;
    }

    reverse(ans.begin(), ans.end());
    return ans;
    
}

int main(){
    string s1 = "abcde";
    string s2 = "bdgek";
    cout << f2(s1, s2);
    return 0;
}