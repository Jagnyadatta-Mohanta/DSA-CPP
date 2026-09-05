class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefMax(n,0), sufMin(n,0);
        int curMax = INT_MIN, curMin = INT_MAX;

        for(int i = 0; i < n; i++){
            curMax = max(curMax,nums[i]);
            prefMax[i] = curMax;
        }

        for(int j = n - 1; j >= 0; j--){
            curMin = min(curMin,nums[j]);
            sufMin[j] = curMin;
        }

        for(int i = 0;i < n; i++){
            if((prefMax[i] - sufMin[i]) <= k){
                return i;
            }
        }
        return -1;
    }
};