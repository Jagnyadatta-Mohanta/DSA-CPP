class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum = 0;
        for(int i = 0; i < k; i++){
            sum = sum + nums[i];
        }
        double maxAverage = (double)sum / k;
        double average = maxAverage;

        for(int j = k; j < nums.size(); j++){
            sum = sum + nums[j] - nums[j - k];
            average = (double)sum / k;
            maxAverage = max(average,maxAverage);
        }

        return maxAverage;
    }
};