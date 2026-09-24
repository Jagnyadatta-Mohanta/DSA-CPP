class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            int n = nums[i];
            int sum = 0, digit;
            while(n != 0){
                digit = n % 10;
                sum = sum + digit;
                n = n / 10;
            }
            if(sum == i){
                return i;
            }
        }
        return -1;
    }
};