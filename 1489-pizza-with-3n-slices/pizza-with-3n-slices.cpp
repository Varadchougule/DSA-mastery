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

    int maxSizeSlices(vector<int>& slices) {
         int k = slices.size();
         vector<vector<int>>dp1(k+1,vector<int>(k+1,-1));
         int case1 = solve(slices, 0, k - 1, k / 3,dp1);
         vector<vector<int>>dp2(k+1,vector<int>(k+1,-1));
         int case2 = solve(slices, 1, k , k / 3,dp2);

         return max(case1, case2);


    }
};