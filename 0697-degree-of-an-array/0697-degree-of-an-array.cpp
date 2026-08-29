class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int,int> freq;
        unordered_map<int,int> firstIndex;
        int degree = 0;
        int minLength = nums.size();

        for(int i = 0; i < nums.size(); i++){
            int x = nums[i];
            if(!firstIndex.count(x)){
                firstIndex[x] = i;
            }

            freq[x]++;

            int length = i - firstIndex[x] + 1;

            if (freq[x] > degree) {
                degree = freq[x];
                minLength = length;
            }
            else if (freq[x] == degree) {
                minLength = min(minLength, length);
            }
        }
        return minLength;
    }
};