class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        int left = 0, right = 0, cur = 0;
        string res(m+n,0);

        while(left < n && right < m){
            res[cur++] = word1[left++];
            res[cur++] = word2[right++];
        }

        if(n < m){
            while(right < m){
                res[cur++] = word2[right++];
            }
        }
        else{
            while(left < n){
                res[cur++] = word1[left++];
            }
        }
        return res;
    }
};