class Solution {
public:
    int solveMem(int n, vector<int>& costs, vector<int>& dp) {
        if(n == 0) {
            return 0;
        }

        if(dp[n] != -1) {
            return dp[n];
        }

        int step1 = solveMem(n-1, costs, dp) + costs[n-1] + 1;

        int step2 = INT_MAX;
        int step3 = INT_MAX;

        if(n >= 2) {
            step2 = solveMem(n-2, costs, dp) + costs[n-1] + 4;
        }

        if(n >= 3) {
            step3 = solveMem(n-3, costs, dp) + costs[n-1] + 9;
        }

        return dp[n] = min({step1, step2, step3});
    }

     int solveTab(int n, vector<int>& costs) {
        vector<int> dp(n+1, -1);
        dp[0] = 0;

        for(int i = 1;i <= n;i++){
            int step1 = dp[i-1] + costs[i-1] + 1;

            int step2 = INT_MAX;
            int step3 = INT_MAX;

            if(i >= 2) {
                step2 = dp[i-2] + costs[i-1] + 4;
            }

            if(i >= 3) {
                step3 = dp[i-3] + costs[i-1] + 9;
            }
            dp[i] = min({step1, step2, step3});
        }

        
        return dp[n];
    }

    int climbStairs(int n, vector<int>& costs) {
        return solveTab(n, costs);
    }
};