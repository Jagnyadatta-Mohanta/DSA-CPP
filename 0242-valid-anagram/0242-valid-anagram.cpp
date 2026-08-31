class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> map1;
        unordered_map<char, int> map2;

        for (char x : s) {
            map1[x]++;
        }

        for (char y : t) {
            map2[y]++;
        }

        if (map1.size() != map2.size()) {
            return false;
        }

        for (auto& pair : map1) {
            if (map2[pair.first] != pair.second) {
                return false;
            }
        }

        return true;
    }
};