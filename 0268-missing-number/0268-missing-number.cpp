class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int numsum = 0, totalsum = 0;
        for(int i = 0; i <= nums.size(); i++){
            totalsum = totalsum + i;
        }
        for(int x : nums){
            numsum = numsum + x;
        }
        return (totalsum - numsum);
    }
};