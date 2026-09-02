class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int result = nums[0]+nums[1]+nums[2];

        for (int i = 0; i < n; i++) {

            int left = i + 1, right = n - 1;

            while (left < right) {

                int sum = nums[left] + nums[i] + nums[right];
                if (abs(sum - target) < abs(result - target)) {
                    result = sum;
                }

                if (sum == target) {
                   return target;
                }

                else if (sum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        return result;
    }
};