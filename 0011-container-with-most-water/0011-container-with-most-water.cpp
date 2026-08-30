class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int maxArea = INT_MIN;

        while (left < right) {
            int area = min(height[left], height[right]) * (right - left);
            maxArea = max(area, maxArea);

            if (height[left] <= height[right]) {
                left++;
            } else if (height[left] > height[right]) {
                right--;
            }
        }
        return maxArea;
    }
};