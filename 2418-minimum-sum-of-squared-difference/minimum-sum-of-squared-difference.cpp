
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        vector<long long> freq(100001, 0);

        long long totalDiff = 0;
        int maxDiff = 0;

        for (int i = 0; i < n; i++) {
            int diff = abs(nums1[i] - nums2[i]);
            freq[diff]++;
            totalDiff += diff;
            maxDiff = max(maxDiff, diff);
        }

        long long k = (long long)k1 + k2;

        if (k >= totalDiff) {
            return 0;
        }

        for (int diff = maxDiff; diff > 0 && k > 0; diff--) {
            long long count = freq[diff];
            long long moves = min(k, count);

            freq[diff] -= moves;
            freq[diff - 1] += moves;
            k -= moves;
        }

        long long sum = 0;

        for (int diff = 1; diff <= maxDiff; diff++) {
            sum += freq[diff] * diff * diff;
        }

        return sum;
    }
};
