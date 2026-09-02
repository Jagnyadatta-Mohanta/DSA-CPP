class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result = "";
        for (int i = 0; i < strs[0].size(); i++) {
            char curChar = strs[0][i];
            for (int j = 1; j < strs.size(); j++) {
                if (curChar != strs[j][i] || strs[j].size() <= i) {
                    return result;
                }
            }
            result = result + curChar;
        }
        return result;
    }
};