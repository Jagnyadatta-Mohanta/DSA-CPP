class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int maxNums = nums[0],n = nums.size();
        int score = 0;
        for(int i = 0; i < n; i++){
            maxNums = max(maxNums,nums[i]);
            int minNums = INT_MAX;
            for(int j = i; j < n; j++){
                minNums = min(minNums,nums[j]);
            }
            score = maxNums - minNums;
            if(score <= k){
                return i;
            }
        }
        return -1;
    }
};