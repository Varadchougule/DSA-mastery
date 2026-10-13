class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        priority_queue<long long> pq;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            pq.push(abs(1LL * nums[i]));
        }

        vector<long long> arr(n, 0);

        // Place largest elements at positive positions
        for (int i = 0; i < n; i += 2) {
            arr[i] = pq.top();
            pq.pop();
        }

        for (int i = 1; i < n; i += 2) {
            arr[i] = pq.top();
            pq.pop();
        }

        long long sum = 0;

        for (int i = 0; i < n; i += 2) {
            sum += arr[i] * arr[i];

            if (i + 1 < n) {
                sum -= arr[i + 1] * arr[i + 1];
            }
        }

        return sum;
    }
};