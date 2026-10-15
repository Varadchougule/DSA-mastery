
class Solution {
public:
    bool isValid(int n) {
        return n >= 1 && n <= 26;
    }

    int solve(string& s, int index, vector<int>& dp, int n) {
        if (index == n) {
            return 1;
        }

        if (s[index] == '0') {
            return 0;
        }

        if (dp[index] != INT_MAX) {
            return dp[index];
        }

        int Single = solve(s, index + 1, dp, n);

        int Double = 0;

        if (index + 1 < n) {
            int num = (s[index] - '0') * 10 + (s[index + 1] - '0');

            if (isValid(num)) {
                Double = solve(s, index + 2, dp, n);
            }
        }

        dp[index] = Single + Double;
        return dp[index];
    }

    int numDecodings(string s) {
        int n = s.length();
        vector<int> dp(n, INT_MAX);
        return solve(s, 0, dp, n);
    }
};
