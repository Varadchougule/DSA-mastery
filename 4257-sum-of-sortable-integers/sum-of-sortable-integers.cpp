
class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        vector<int> Kdivisor;

        for (int i = 1; i <= n; i++) {
            if (n % i == 0) {
                Kdivisor.push_back(i);
            }
        }

        for (int k : Kdivisor) {
            bool valid = true;
            int prevMax = 0;

            for (int s = 0; s < n; s += k) {
                int mn = nums[s];
                int mx = nums[s];
                int count = 0;

                for (int i = s; i < s + k; i++) {
                    int j = (i + 1 == s + k) ? s : i + 1;

                    if (nums[i] > nums[j]) {
                        count++;
                    }

                    mn = min(mn, nums[i]);
                    mx = max(mx, nums[i]);
                }

                if (count > 1) {
                    valid = false;
                    break;
                }

                if (s > 0 && prevMax > mn) {
                    valid = false;
                    break;
                }

                prevMax = mx;
            }

            if (valid) {
                ans += k;
            }
        }

        return ans;
    }
};
