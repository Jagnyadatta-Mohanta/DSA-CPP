class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int len = m + n - 1;

        // A valid string must have even length
        if (len % 2 != 0)
            return false;

        // A valid path cannot start with ')' or end with '('
        if (grid[0][0] == ')' || grid[m - 1][n - 1] == '(')
            return false;

        vector<vector<vector<bool>>> dp(
            m, vector<vector<bool>>(n, vector<bool>(len + 1, false))
        );

        // Starting cell
        dp[0][0][1] = true;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                for (int bal = 0; bal <= len; bal++) {
                    if (!dp[i][j][bal])
                        continue;

                    // Move down
                    if (i + 1 < m) {
                        int next = bal + (grid[i + 1][j] == '(' ? 1 : -1);

                        if (next >= 0)
                            dp[i + 1][j][next] = true;
                    }

                    // Move right
                    if (j + 1 < n) {
                        int next = bal + (grid[i][j + 1] == '(' ? 1 : -1);

                        if (next >= 0)
                            dp[i][j + 1][next] = true;
                    }
                }
            }
        }

        return dp[m - 1][n - 1][0];
    }
};