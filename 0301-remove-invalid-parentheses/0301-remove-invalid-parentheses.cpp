class Solution {
public:
    unordered_set<string> ans;

    void dfs(string& s, int i, int left, int right, int balance, string& path) {
        if (balance < 0)
            return;

        if (i == s.size()) {
            if (left == 0 && right == 0 && balance == 0)
                ans.insert(path);
            return;
        }

        if (s[i] == '(') {
            // Remove
            if (left > 0)
                dfs(s, i + 1, left - 1, right, balance, path);

            // Keep
            path.push_back('(');
            dfs(s, i + 1, left, right, balance + 1, path);
            path.pop_back();
        }
        else if (s[i] == ')') {
            // Remove
            if (right > 0)
                dfs(s, i + 1, left, right - 1, balance, path);

            // Keep only if it can be matched
            if (balance > 0) {
                path.push_back(')');
                dfs(s, i + 1, left, right, balance - 1, path);
                path.pop_back();
            }
        }
        else {
            path.push_back(s[i]);
            dfs(s, i + 1, left, right, balance, path);
            path.pop_back();
        }
    }

    vector<string> removeInvalidParentheses(string s) {
        int left = 0, right = 0;

        // Find minimum number of removals
        for (char c : s) {
            if (c == '(') {
                left++;
            }
            else if (c == ')') {
                if (left > 0)
                    left--;
                else
                    right++;
            }
        }

        string path;
        dfs(s, 0, left, right, 0, path);

        return vector<string>(ans.begin(), ans.end());
    }
};