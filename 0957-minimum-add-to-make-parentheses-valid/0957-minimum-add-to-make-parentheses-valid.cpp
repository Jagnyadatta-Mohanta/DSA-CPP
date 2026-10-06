class Solution {
public:
    int minAddToMakeValid(string s) {
        int stack = 0, ans = 0;
        for (char ch : s) {
            if (ch == '(') {
                stack++;
            } else {
                if (stack > 0)
                    stack--;
                else
                    ans++;
            }
        }

        return stack + ans;
    }
};