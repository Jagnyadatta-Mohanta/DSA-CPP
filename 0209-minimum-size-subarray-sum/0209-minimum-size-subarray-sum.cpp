class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int len = 0,minLen = INT_MAX;
        int left = 0,right = 0;
        int sum = 0;

        while(right < nums.size()){
            sum = sum + nums[right];
            while(sum >= target){
                len = right - left + 1;
                minLen = min(len,minLen);
                sum = sum - nums[left];
                left++;
            }
            right++;
        }
        return minLen == INT_MAX ? 0 : minLen;
    }
};