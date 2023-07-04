#include <bits/stdc++.h>
using namespace std;

//Minimum insertion to make a string palindrome

void f2(string s2){
    string s1 = s2;
    reverse(s2.begin(), s2.end());
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
    
    cout << "Number of operations required: " << s1.length() - dp[n1][n2] << endl;
}


int main(){
    string s = "abzcaa";
    f2(s);
    return 0;
}