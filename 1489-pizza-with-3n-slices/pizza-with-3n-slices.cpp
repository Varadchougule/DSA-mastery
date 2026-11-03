class Solution {
public:
    int solve(vector<int>& slices, int index, int endingIndex, int n,vector<vector<int>>&dp) {
        if (n == 0 ) {
            return 0;
        }
        if(index >= endingIndex){
            return INT_MIN;
        }

        if(dp[index][n] != -1){
            return dp[index][n];
        }

        int incl = slices[index] + solve(slices, index + 2, endingIndex, n - 1,dp);

        int excl = solve(slices, index + 1, endingIndex, n,dp);

        return dp[index][n] = max(incl, excl);
    }

    int solveTab(vector<int>&slices){
        int k = slices.size();
        vector<vector<int>>dp1(k+2,vector<int>(k+2,0));
        vector<vector<int>>dp2(k+2,vector<int>(k+2,0));

        for(int index = k-2;index >= 0;index--){
            for(int n = 1;n <= k/3;n++){
                int incl = slices[index] + dp1[index + 2][n - 1];

                int excl = dp1[index + 1][n];

                dp1[index][n] = max(incl,excl);
            }
        }
        
        int case1 = dp1[0][k/3];

        for(int index = k-1;index >= 1;index--){
            for(int n = 1;n <= k/3;n++){
                int incl = slices[index] + dp2[index + 2][n - 1];

                int excl = dp2[index + 1][n];

                dp2[index][n] = max(incl,excl);
            }
        }
        
        int case2 = dp2[1][k/3];
        return max(case1,case2);
    }

    int solveSO(vector<int>&slices){
        int k = slices.size();
        vector<int>prev1(k+2,0);
        vector<int>curr1(k+2,0);
        vector<int>next1(k+2,0);

        vector<int>prev2(k+2,0);
        vector<int>curr2(k+2,0);
        vector<int>next2(k+2,0);

        for(int index = k-2;index >= 0;index--){
            for(int n = 1;n <= k/3;n++){
                int incl = slices[index] + next1[n - 1];

                int excl = curr1[n];

                prev1[n] = max(incl,excl);
            }
           next1 = curr1;
           curr1 = prev1;
        }
        
        int case1 = curr1[k/3];

        for(int index = k-1;index >= 1;index--){
            for(int n = 1;n <= k/3;n++){
                int incl = slices[index] + next2[n - 1];

                int excl = curr2[n];

                prev2[n] = max(incl,excl);
            }
            next2 = curr2;
            curr2 = prev2;
        }
        
        int case2 = curr2[k/3];
        return max(case1,case2);
    }

    int maxSizeSlices(vector<int>& slices) {
         int k = slices.size();
        //  vector<vector<int>>dp1(k+1,vector<int>(k+1,-1));
        //  int case1 = solve(slices, 0, k - 1, k / 3,dp1);
        //  vector<vector<int>>dp2(k+1,vector<int>(k+1,-1));
        //  int case2 = solve(slices, 1, k , k / 3,dp2);

        //  return max(case1, case2);
        
        //return solveTab(slices);

        return solveSO(slices);

    }
};