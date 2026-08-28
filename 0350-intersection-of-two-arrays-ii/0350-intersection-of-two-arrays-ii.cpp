class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp1;
        vector<int> result;

        for(int x : nums1){
            mp1[x]++;
        }

        for(int x : nums2){
            if(mp1[x] > 0){
                result.push_back(x);
                mp1[x]--;
            }
        }
        return result;        
    }
};