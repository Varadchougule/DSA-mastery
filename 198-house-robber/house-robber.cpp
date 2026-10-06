
class Solution {
public:
    int solve(vector<int>& nums) {
        int n = nums.size();

        if (n == 0) return 0;

        int prev2 = 0;
        int prev1 = nums[0];

        for (int i = 1; i < n; i++) {
            int incl = prev2 + nums[i];
            int excl = prev1;

            int ans = max(incl, excl);

            prev2 = prev1;
            prev1 = ans;
        }

        return prev1;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) return nums[0];

        return solve(nums);
    }
};