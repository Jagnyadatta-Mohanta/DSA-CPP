class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int left = 0,right = left + 1;
        int window = 1,maxWindow = window;

        while(right < nums.size()){
            if(nums[left] < nums[right]){
                window++;
                maxWindow = max(window,maxWindow);
            }
            else{
                window = 1;
            }
            right++;
            left++;
        }
        return maxWindow;
    }
};