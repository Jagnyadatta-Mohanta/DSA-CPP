class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> unique;
        for(int i: nums){
            if(unique.count(i)){
                return true;
            }
            unique.insert(i);
        }
        return false;
    }
};