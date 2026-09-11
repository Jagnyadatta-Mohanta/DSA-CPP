class Solution {
public:
    string reversePrefix(string word, char ch) {
        int left = 0, right = 0;

        for(int i = 0; i < word.size(); i++){
            if(word[i] == ch){
                right = i;
                break;
            }
        }
        if(right == 0){
            return word;
        }

        while(left < right){
            swap(word[left++],word[right--]);
        }
        return word;
    }
};