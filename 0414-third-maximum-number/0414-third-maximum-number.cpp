class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long first = LLONG_MIN,second = LLONG_MIN,third = LLONG_MIN;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == first || nums[i] == second || nums[i] == third){
                continue;
            }
            else if(nums[i] > first){
                third = second;
                second = first;
                first = nums[i];
            }
            else if(nums[i] > second){
                third = second;
                second = nums[i];

            }
             else if(nums[i] > third){
                third = nums[i];
            }
        }
        if(!(third == LLONG_MIN)){
            return third;
        }
        else{
            return first;
        }
    }
};