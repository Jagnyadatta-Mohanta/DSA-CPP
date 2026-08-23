class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> unique(nums.begin(),nums.end());
        if(nums.size() == unique.size()){
            return false;
        }
        return true;
    }
};