#include <bits/stdc++.h>
using namespace std;

// Partition subset into 2 subsets such that difference is minimum
int paritionArray(vector<int> arr)
{
    int target = 0;
    for (auto i : arr)
    {
        target += i;
    }

    vector<vector<bool>> dp(arr.size(), vector<bool>(target + 1, false));
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = true;
    }

    dp[0][arr[0]] = true;

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= target; j++)
        {
            bool notTake = dp[i - 1][j];
            bool take = false;
            if (arr[i] <= j)
            {
                take = dp[i - 1][j - arr[i]];
            }
            dp[i][j] = notTake | take;
        }
    }

    int minDiff = 1e9;
    for(int i = 0; i <= target/2; i++){
        if(dp[n-1][i] == true){
            minDiff = min(minDiff, abs(target-i) - i);
        }
    }

    return minDiff;

}

int main()
{

    vector<int> arr = {6,5,1,0};
    cout << paritionArray(arr);

    return 0;
}