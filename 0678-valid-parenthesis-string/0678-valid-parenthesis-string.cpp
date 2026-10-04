class Solution {
public:
    bool checkValidString(string s) {
        int low = 0, high = 0;

        for (char ch : s) {
            if (ch == '(') {
                low++;
                high++;
            }
            else if (ch == ')') {
                low = max(0, low - 1);
                high--;
            }
            else { // '*'
                low = max(0, low - 1); // '*' acts as ')'
                high++;                // '*' acts as '('
            }

            if (high < 0)
                return false;
        }

        return low == 0;
    }
};