class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();

        // dp[i][j] = true if s[i...j] is a palindrome
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        // Build palindrome table
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] == s[j] && (j - i <= 1 || dp[i + 1][j - 1])) {
                    dp[i][j] = true;
                }
            }
        }

        // greedy: choose the earliest-ending palindrome
        int ans = 0;
        int start = 0;

        for (int end = 0; end < n; end++) {
            for (int i = start; i <= end - k + 1; i++) {
                if (dp[i][end]) {
                    ans++;
                    start = end + 1;
                    break;
                }
            }
        }

        return ans;
    }
};