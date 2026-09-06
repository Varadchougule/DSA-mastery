class Solution {
public:
    int countGoodRotations(vector<int>& nums) {

        int good = 0;
        int n = nums.size();
        int half = n / 2;

        long long totalSum = 0;

        for(int i = 0; i < n; i++) {
            totalSum += nums[i];
        }

        long long firstSum = 0;

        for(int i = 0; i < half; i++) {
            firstSum += nums[i];
        }

        for(int i = 0; i < n; i++) {

            long long secondSum = totalSum - firstSum;

            if(firstSum < secondSum) {
                good++;
            }

            firstSum = firstSum
                     - nums[i]
                     + nums[(i + half) % n];
        }

        return good;
    }
};