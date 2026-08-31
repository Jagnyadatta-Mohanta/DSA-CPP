class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++){
            while(nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1]){
                swap(nums[i],nums[nums[i] - 1]);
            }
        }
        for (int p = 0; p < n; p++) {
            if (nums[p] != p + 1) {
                return p + 1;
            }
        }
        return n + 1;
    }
};