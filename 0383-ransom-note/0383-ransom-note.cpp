class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> ransome,mag;

        for(char s : ransomNote){
            ransome[s]++;
        }
        for(char s : magazine){
            mag[s]++;
        }

        for(auto x : ransome){
            if(x.second > mag[x.first]){
                return false;
            }
        }
        return true;
    }
};