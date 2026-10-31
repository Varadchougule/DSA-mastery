class Solution {
public:
    int solve(vector<vector<int>>& grid, int i, int j, int dir,
              vector<vector<vector<int>>>& dp) {

        int n = grid.size();
        int m = grid[0].size();
        int mod = 1e9 + 7;

        if (i >= n || j >= m)
            return 0;

        if (i == n - 1 && j == m - 1)
            return 1;

        if (dp[i][j][dir] != -1)
            return dp[i][j][dir];

        int ans = 0;

        if (grid[i][j] == 1) {
            if (dir == 0)
                ans = solve(grid, i + 1, j, 1, dp);
            else
                ans = solve(grid, i, j + 1, 0, dp);

            ans %= mod;
        }
        else {
            ans = (solve(grid, i + 1, j, 1, dp) % mod
                + solve(grid, i, j + 1, 0, dp) % mod) % mod;
        }

        return dp[i][j][dir] = ans;
    }

    int uniquePaths(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(m, vector<int>(2, -1))
        );

        return solve(grid, 0, 0, 0, dp);
    }
};