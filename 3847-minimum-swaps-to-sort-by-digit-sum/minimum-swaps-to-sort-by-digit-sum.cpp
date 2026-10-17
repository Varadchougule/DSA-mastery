class Solution {
public:
    int digitSum(int x) {
        int sum = 0;

        while (x > 0) {
            sum += x % 10;
            x /= 10;
        }

        return sum;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        vector<pair<int, int>> v;

        for (int i = 0; i < n; i++) {
            v.push_back({digitSum(nums[i]), nums[i]});
        }

        sort(v.begin(), v.end());

        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++) {
            mp[v[i].second] = i;
        }

        vector<int> pos(n);

        for (int i = 0; i < n; i++) {
            pos[i] = mp[nums[i]];
        }

        int count = 0;
        vector<bool> visited(n, false);

        for (int i = 0; i < n; i++) {
            if (visited[i] || pos[i] == i) {
                continue;
            }

            int cycle = 0;
            int j = i;

            while (!visited[j]) {
                visited[j] = true;
                j = pos[j];
                cycle++;
            }

            count += cycle - 1;
        }

        return count;
    }
};