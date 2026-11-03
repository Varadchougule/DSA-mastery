class Solution {
public:
    int solveMem(vector<int>& nums1, vector<int>& nums2,int index,int swapped,vector<vector<int>>&dp){
        if(index >= nums1.size()){
            return 0;
        }

        if(dp[index][swapped] != INT_MAX){
            return dp[index][swapped];
        }

        int ans = INT_MAX;

        int prev1 = nums1[index - 1];
        int prev2 = nums2[index - 1];

        if(swapped){
            swap(prev1,prev2);
        }     
        //nonswap
        if(nums1[index] > prev1 && nums2[index] > prev2){
            ans = solveMem(nums1,nums2,index+1,0,dp);
        }

        if(nums1[index] > prev2 && nums2[index] > prev1){
            ans = min(ans,1 + solveMem(nums1,nums2,index+1,1,dp));
        }
        return dp[index][swapped] = ans;
    }

    int solveTab(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        for (int index = n - 1; index >= 1; index--) {
            for (int swapped = 1; swapped >= 0; swapped--) {

                int ans = INT_MAX;

                int prev1 = nums1[index - 1];
                int prev2 = nums2[index - 1];

                if (swapped) {
                    swap(prev1, prev2);
                }

                // No swap
                if (nums1[index] > prev1 && nums2[index] > prev2) {
                    ans = dp[index + 1][0];
                }

                // Swap
                if (nums1[index] > prev2 && nums2[index] > prev1) {
                    ans = min(ans, 1 + dp[index + 1][1]);
                }

                dp[index][swapped] = ans;
            }
        }
        return min(dp[1][0],1 +dp[1][1]);
        }

        int solveSO(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int>next(2,0);
        vector<int>curr(2,0);
        
        for (int index = n - 1; index >= 1; index--) {
            for (int swapped = 1; swapped >= 0; swapped--) {

                int ans = INT_MAX;

                int prev1 = nums1[index - 1];
                int prev2 = nums2[index - 1];

                if (swapped) {
                    swap(prev1, prev2);
                }

                // No swap
                if (nums1[index] > prev1 && nums2[index] > prev2) {
                    ans = next[0];
                }

                // Swap
                if (nums1[index] > prev2 && nums2[index] > prev1) {
                    ans = min(ans, 1 + next[1]);
                }

                curr[swapped] = ans;
            }
            next = curr;
        }

        return min(next[0], 1 + next[1]);
    }

    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
       //int swapped = 0;
       // nums1.insert(nums1.begin(),-1);
       // nums2.insert(nums2.begin(),-1);
       //vector<vector<int>>dp(n+1,vector<int>(2,INT_MAX));
        //return solveMem(nums1,nums2,1,swapped,dp);

       // return solveTab(nums1,nums2);

       return solveSO(nums1,nums2);
    }
};