import java.util.*;

public class Dp3 {
    // Recursion approach
    static int solve1(int ind, int arr[]) {
        if (ind == 0)
            return 0;

        int w1 = Integer.MAX_VALUE;
        int w2 = Integer.MAX_VALUE;
        w1 = solve1(ind - 1, arr) + Math.abs(arr[ind] - arr[ind - 1]);
        if (ind > 1) {
            w2 = solve1(ind - 2, arr) + Math.abs(arr[ind] - arr[ind - 2]);
        }
        return Math.min(w1, w2);
    }

    // Memoization
    static int solve2(int ind, int arr[], int dp[]) {
        if (ind <= 0)
            return 0;

        int w1 = Integer.MAX_VALUE;
        int w2 = Integer.MAX_VALUE;
        if(dp[ind] != -1)return dp[ind];
        w1 = solve1(ind - 1, arr) + Math.abs(arr[ind] - arr[ind - 1]);
        if (ind > 1) {
            w2 = solve1(ind - 2, arr) + Math.abs(arr[ind] - arr[ind - 2]);
        }
        return dp[ind] = Math.min(w1, w2);
    }

    //Tabulation 
    static int solve3(int arr[]){
        int dp[] = new int[arr.length];
        dp[0] = 0;
        for(int i = 1; i < arr.length; i++){
            int left = Math.abs(arr[i] - arr[i-1]) + dp[i-1];
            int right = Integer.MAX_VALUE;
            if(i > 2){
                right = Math.abs(arr[i] - arr[i-2]) + dp[i-2];
            }
            dp[i] = Math.min(left, right);
        }

        return dp[arr.length-1];
    }

    public static void main(String[] args) {
        int arr[] = { 10, 20, 30, 10 };
        int dp[] = new int[arr.length];
        Arrays.fill(dp,-1);
        // System.out.println(solve1(arr.length - 1, arr));
        // System.out.println(solve2(arr.length-1, arr,dp));
        System.out.println(solve3(arr));
    }
}
