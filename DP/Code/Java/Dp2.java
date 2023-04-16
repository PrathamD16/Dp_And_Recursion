import java.util.Arrays;

public class Dp2{
    //Recursion Approach
    public static int solve(int n){
        if(n <= 1)return n;
        return solve(n-1) + solve(n-2);
    }

    //Memoization
    public static int Memoization(int n, int dp[]){
        if(n <= 1)return n;
        if(dp[n] != -1)return dp[n];
        return dp[n] = solve(n-1) + solve(n-2);
    }

    //tabulation
    public static int tabulation(int n){
        int pre1 = 0;
        int pre2 = 1;
        for(int i = 2; i <= n; i++){
            int temp = pre1+pre2;
            pre1 = pre2;
            pre2 = temp;
        }
        return pre2;
    }
    public static void main(String[] args) {
        int dp[] = new int[6];
        Arrays.fill(dp,-1);
        int n = 4;
        System.out.println(tabulation(n+1));
    }
}