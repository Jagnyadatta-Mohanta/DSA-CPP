class Solution {
public:
    bool validPalindrome(string s) {
        int left =0, right = s.size() - 1;
        while (left < right) {

            if (s[left] == s[right]) {
                left++;
                right--;
            } else {
                int r1 = right;
                int l1 = left + 1;
                while (l1 < r1 && s[l1] == s[r1]) {
                    if (s[l1] == s[r1]) {
                        l1++;
                        r1--;
                    }
                }

                int r2 = right - 1;
                int l2 = left;
                while (l2 < r2 && s[l2] == s[r2]) {
                    if (s[l2] == s[r2]) {
                        l2++;
                        r2--;
                    }
                }

                return l1 >= r1 || l2 >= r2;
            }
        }
        return 1;
    }
};