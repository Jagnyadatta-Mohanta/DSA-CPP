class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int last_result = m + n - 1;
        int last_nums1 = m - 1;
        int last_nums2 = n - 1;

        while (last_nums1 >= 0 && last_nums2 >= 0) {

            if (nums1[last_nums1] > nums2[last_nums2]) {
                nums1[last_result] = nums1[last_nums1];
                last_nums1--;
            }
            else {
                nums1[last_result] = nums2[last_nums2];
                last_nums2--;
            }

            last_result--;
        }

        while (last_nums2 >= 0) {
            nums1[last_result] = nums2[last_nums2];
            last_nums2--;
            last_result--;
        }
    }
};