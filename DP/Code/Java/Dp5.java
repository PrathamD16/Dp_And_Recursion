
//House Robber
import java.util.*;

public class Dp5 {
    // Recursion approach
    static int solve1(int ind, int arr[]) {
        if (ind < 0)
            return 0;
        if (ind == 0)
            return arr[ind];

        int pick = arr[ind] + solve1(ind - 2, arr);

        int not_pick = 0 + solve1(ind - 1, arr);
        return Math.max(pick, not_pick);
    }

    // MemoiZation
    static int solve2(int ind, int arr[], int dp[]) {
        if (ind < 0)
            return 0;
        if (ind == 0)
            return dp[ind] = arr[ind];

        if (dp[ind] != -1)
            return dp[ind];
        int pick = arr[ind] + solve2(ind - 2, arr, dp);
        int not_pick = 0 + solve2(ind - 1, arr, dp);
        return dp[ind] = Math.max(pick, not_pick);
    }

    // Tabulation
    static int solve3(int arr[]) {
        int dp[] = new int[arr.length];
        dp[0] = arr[0];
        for (int i = 1; i < arr.length; i++) {
            int pick = Integer.MIN_VALUE;
            if (i > 1) {
                pick = arr[i] + dp[i - 2];
            }
            int not_pick = dp[i-1];
            dp[i] = Math.max(pick, not_pick);
        }
        return dp[arr.length-1];
    }

    //Adjacent element where we consider first and last element as adjacent;
    static int solve4(int arr[]){
        int arr1[] = new int[arr.length-1];
        int arr2[] = new int[arr.length-1];
        int j = 0,k = 0;
        for(int i = 0; i < arr.length; i++){
            if(i != 0){
                arr1[j] = arr[i];
                j++;
            }
            if(i != arr.length-1){
                arr2[k] = arr[i];
                k++;
            }
        }

        return Math.max(solve3(arr1), solve3(arr2));
    }

    public static void main(String[] args) {
        // int arr[] = { 1, 2, 3, 1, 1, 6 };
        int arr[] = { 2, 1, 4, 9 };
        int dp[] = new int[arr.length];
        Arrays.fill(dp, -1);
        // System.out.println(solve2(arr.length - 1, arr, dp));
        // System.out.println(solve1(arr.length - 1, arr));
        // System.out.println(solve3(arr));
        System.out.println(solve4(arr));
    }
}
