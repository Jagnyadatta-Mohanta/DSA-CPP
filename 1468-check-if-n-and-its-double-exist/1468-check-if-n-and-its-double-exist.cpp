class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        for(int i = 0; i < arr.size(); i++){
            int num = arr[i]*2;
            auto j = find(arr.begin(), arr.end(), num);
            if(j != arr.end()){
                if(i != j - arr.begin()){
                  return 1;
                }
            }
        }
        return 0;
    }
};