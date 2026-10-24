class Solution {
public:
    int solve(vector<int>&obstacles,int currlane,int currpos){
        int n = obstacles.size() - 1;
        if (currpos == n) {
            return 0;
        }

        if (obstacles[currpos + 1] != currlane) {
            return solve(obstacles, currlane, currpos + 1);
        }
        else {
            int ans = 1e9;

            for (int i = 1; i <= 3; i++) {
                if (currlane != i && obstacles[currpos] != i) {
                    ans = min(ans, 1 + solve(obstacles, i, currpos));
                }
            }

            return ans;
        }
    }

    int solveMen(vector<int>&obstacles,int currlane,int currpos,vector<vector<int>>dp){
        int n = obstacles.size() - 1;
        if (currpos == n) {
            return 0;
        }
        if(dp[currlane][currpos] != -1){
            return dp[currlane][currpos];
        }

        if (obstacles[currpos + 1] != currlane) {
            return solveMen(obstacles, currlane, currpos + 1,dp);
        }
        else {
            int ans = 1e9;

            for (int i = 1; i <= 3; i++) {
                if (currlane != i && obstacles[currpos] != i) {
                    ans = min(ans, 1 + solveMen(obstacles, i, currpos,dp));
                }
            }
            dp[currlane][currpos] = ans;

            return ans;
        }
    }
        int solveTab(vector<int>& obstacles) {
        int n = obstacles.size() - 1;

        vector<vector<int>> dp(4, vector<int>(n + 1, 1e9));

        dp[0][n] = 0;
        dp[1][n] = 0;
        dp[2][n] = 0;
        dp[3][n] = 0;

        for (int currpos = n - 1; currpos >= 0; currpos--) {
            for (int currlane = 1; currlane <= 3; currlane++) {

                if (obstacles[currpos + 1] != currlane) {
                    dp[currlane][currpos] = dp[currlane][currpos + 1];
                }
                else {
                    int ans = 1e9;

                    for (int i = 1; i <= 3; i++) {
                        if (currlane != i && obstacles[currpos] != i) {
                            ans = min(ans, 1 + dp[i][currpos + 1]);
                        }
                    }

                    dp[currlane][currpos] = ans;
                }
            }
        }

        return min({dp[1][0] + 1, dp[2][0], dp[3][0] + 1});
    }
    int minSideJumps(vector<int>& obstacles) {
        //return solve(obstacles,2,0);

        //vector<vector<int>>dp(4,vector<int>(obstacles.size(),-1));
        //return solveMen(obstacles,2,0,dp);

        return solveTab(obstacles);
    }
};