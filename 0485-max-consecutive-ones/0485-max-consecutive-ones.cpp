class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int counter = 0,maxC = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 1){
                counter++;
                maxC = max(maxC,counter);
            }
            else{
                counter = 0;
            }
        }

        return maxC;
    }
};