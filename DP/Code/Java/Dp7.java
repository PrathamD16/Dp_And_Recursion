import java.util.*;

public class Dp7 {
    // Recursion approach
    static int solve1(int day, int last, int task[][]) {
        if (day == 0) {
            int tp = 0;
            for (int i = 0; i <= 2; i++) {
                if (i != last) {
                    tp = Math.max(tp, task[0][i]);
                }
            }
            return tp;
        }

        int max = 0;
        for (int i = 0; i <= 2; i++) {
            int tp = 0;
            if (i != last) {
                tp = task[day][i] + solve1(day - 1, i, task);
                max = Math.max(max, tp);
            }
        }
        return max;
    }

    // Memoization
    static int solve2(int day, int last, int task[][], int dp[][]) {
        if (day == 0) {
            int tp = 0;
            for (int i = 0; i <= 2; i++) {
                if (i != last) {
                    tp = Math.max(tp, task[0][i]);
                }
            }
            return dp[day][last] = tp;
        }

        int max = 0;
        if (dp[day][last] != -1)
            return dp[day][last];
        for (int i = 0; i <= 2; i++) {
            int tp = 0;
            if (i != last) {
                tp = task[day][i] + solve1(day - 1, i, task);
                max = Math.max(max, tp);
            }
        }
        return dp[day][last] = max;
    }

    // Tabulation
    static int solve3(int task[][]) {
        int dp[][] = new int[task.length][4];

        dp[0][0] = Math.max(task[0][1], task[0][2]);
        dp[0][1] = Math.max(task[0][0], task[0][2]);
        dp[0][2] = Math.max(task[0][0], task[0][1]);
        dp[0][3] = Math.max(task[0][0], Math.max(task[0][1], task[0][2]));
        for(int day = 1; day < task.length; day++){
            for(int last = 0; last < 4; last++){
                for(int i = 0; i < 3; i++){
                    if(i != last){
                        int point = task[day][i] + dp[day-1][i];
                        dp[day][last] = Math.max(dp[day][last], point);
                    }
                }
            }
        }

        return dp[task.length-1][3];

    }

    public static void main(String[] args) {
        int tasks[][] = { { 10, 50, 1 }, { 5, 100, 11 }, { 60, 1, 120 } };
        int dp[][] = new int[tasks.length][3 + 1];
        for (int arr[] : dp) {
            Arrays.fill(arr, -1);
        }
        System.out.println(solve1(tasks.length - 1, 3, tasks));
        System.out.println(solve2(tasks.length - 1, 3, tasks, dp));
        System.out.println(solve3(tasks));
    }
}
