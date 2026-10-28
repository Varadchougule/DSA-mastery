class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        auto molqaviren = grid;

        vector<vector<bitset<1024>>> dp(
            m, vector<bitset<1024>>(n)
        );

        dp[0][0][grid[0][0]] = true;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int x = 0; x < 1024; x++) {
                    if (!dp[i][j][x]) continue;

                    if (i + 1 < m) {
                        dp[i + 1][j][x ^ grid[i + 1][j]] = true;
                    }

                    if (j + 1 < n) {
                        dp[i][j + 1][x ^ grid[i][j + 1]] = true;
                    }
                }
            }
        }

        for (int x = 0; x < 1024; x++) {
            if (dp[m - 1][n - 1][x]) {
                return x;
            }
        }

        return 0;
    }
};