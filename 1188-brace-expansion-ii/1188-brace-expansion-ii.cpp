class Solution {
public:

    vector<string> dfs(const string& s, int l, int r) {
        set<string> result;

        vector<vector<string>> groups(1);

        int balance = 0;
        int start = 0;

        for (int i = l; i <= r; i++) {

            if (s[i] == '{') {
                balance++;

                if (balance == 1)
                    start = i + 1;
            }

            else if (s[i] == '}') {
                balance--;

                if (balance == 0) {
                    vector<string> inside = dfs(s, start, i - 1);

                    if (groups.back().empty()) {
                        groups.back() = inside;
                    }
                    else {
                        vector<string> temp;

                        for (string a : groups.back()) {
                            for (string b : inside) {
                                temp.push_back(a + b);
                            }
                        }

                        groups.back() = temp;
                    }
                }
            }

            else if (s[i] == ',' && balance == 0) {
                groups.push_back({});
            }

            else if (balance == 0) {
                string ch(1, s[i]);

                if (groups.back().empty()) {
                    groups.back().push_back(ch);
                }
                else {
                    for (string &x : groups.back())
                        x += ch;
                }
            }
        }

        for (auto &group : groups) {
            for (auto &word : group) {
                result.insert(word);
            }
        }

        return vector<string>(result.begin(), result.end());
    }


    vector<string> braceExpansionII(string expression) {
        return dfs(expression, 0, expression.size() - 1);
    }
};