class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> visited;

        for(int x : arr){
            if(visited.count(x * 2) || (visited.count(x / 2) && x % 2 == 0)){
                return 1;
            }
            visited.insert(x);
        }
        return 0;
    }
};