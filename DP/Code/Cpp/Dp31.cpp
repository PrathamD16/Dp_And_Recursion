#include <bits/stdc++.h>
using namespace std;

// Shorted common supersequence

// Print the length of sub-sequence and print the letter itself

void f1(string s1, string s2)
{
    int n1 = s1.size();
    int n2 = s2.size();
    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
    for (int i = 1; i <= n1; i++)
    {
        for (int j = 1; j <= n2; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    cout << "Length of supersequence is: " << n1 + n2 - dp[n1][n2] << endl;

    // printing the supersequence
    int i = n1, j = n2;
    string ans = "";
    while (i > 0 && j > 0)
    {
        if (s1[i - 1] == s2[j - 1])
        {
            ans = ans + s1[i - 1];
            i--;
            j--;
        }
        else
        {
            if (dp[i - 1][j] > dp[i][j - 1])
            {
                ans += s1[i - 1];
                i--;
            }
            else
            {
                ans += s2[j - 1];
                j--;
            }
        }
    }

    while (i > 0)
    {
        ans += s1[i - 1];
        i--;
    }

    while (j > 0)
    {
        ans += s2[j - 1];
        j--;
    }

    reverse(ans.begin(), ans.end());
    cout << "Supersequence string is: " << ans << endl;
}

int main()
{
    string s1 = "brute";
    string s2 = "groot";
    f1(s1, s2);
    return 0;
}