class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0, right = 0, counter = 0;
        int len = 0;

        while (right < nums.size()) {
            if (nums[right] == 0) {
                counter++;
            }
            if (counter > k) {
                if (nums[left] == 0) {
                    counter--;
                }
                left++;
            }
            len = max(len, right - left + 1);
            right++;
        }
        return len;
    }
};