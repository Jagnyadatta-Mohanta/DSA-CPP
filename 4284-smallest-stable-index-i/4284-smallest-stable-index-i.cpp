class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> suffixMin(n);

        suffixMin[n - 1] = nums[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            suffixMin[i] = min(nums[i], suffixMin[i + 1]);
        }
        int maxNums = INT_MIN;

        for (int i = 0; i < n; i++) {
            maxNums = max(maxNums, nums[i]);

            int score = maxNums - suffixMin[i];

            if (score <= k) {
                return i;
            }
        }

        return -1;
    }
};