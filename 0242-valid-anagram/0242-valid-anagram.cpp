class Solution {
public:
    bool isAnagram(string s, string t) {
        int vote[26] = {0};

        for (char x : s) {
            vote[x - 'a']++;
        }

        for (char y : t) {
            vote[y - 'a']--;
        }
        for (int x : vote) {
            if (x != 0) {
                return false;
            }
        }
        return true;
    }
};