class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int maxLeft = INT_MIN, maxRight = INT_MIN;
        int water = 0;

        while (left < right) {
            if (height[left] <= height[right]) {
                maxLeft = max(maxLeft, height[left]);
                water = water + maxLeft - height[left];
                left++;
            }
            else {
                maxRight = max(maxRight, height[right]);
                water = water + maxRight - height[right];
                right--;
            }
        }
        return water;
    }
};