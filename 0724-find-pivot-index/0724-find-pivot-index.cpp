class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sumLeft = 0;
        int totalSum = 0;

        for(int x : nums){
            totalSum = totalSum + x;
        }

        for(int i = 0; i < nums.size(); i++){
            int sumRight = totalSum - nums[i] - sumLeft;

            if(sumLeft == sumRight){
                return i;
            }

            sumLeft = sumLeft + nums[i];

        } 
      return -1;
    }
};