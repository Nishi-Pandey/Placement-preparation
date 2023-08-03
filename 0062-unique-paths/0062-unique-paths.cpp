class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));

        // Number of unique paths for the top-left cell
        dp[0][0] = 1;

        // Calculate number of unique paths for each cell
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i > 0) {
                    dp[i][j] += dp[i - 1][j];
                }
                if (j > 0) {
                    dp[i][j] += dp[i][j - 1];
                }
            }
        }

        // Number of unique paths for the bottom-right cell
        return dp[m - 1][n - 1];
    }
};
