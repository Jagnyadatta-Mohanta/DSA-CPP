class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int leader = nums[0], vote = 1;

        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == leader){
                vote++;
            }
            else if(vote == 0){
                leader = nums[i];
                vote++;
            }
            else{
                vote--;
            }

        }
        return leader;
    }
};