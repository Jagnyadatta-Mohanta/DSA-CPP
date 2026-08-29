class Solution {
public:
    int findMin(vector<int>& nums) {
        int minimum = INT_MAX;
        for(int x : nums){
            minimum = min(minimum,x);
        }

        return minimum;
    }
};