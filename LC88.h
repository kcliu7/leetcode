class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int id = m+n-1, im = m-1, in = n-1;
        while(id>=0 && im>=0 && in>=0){
            if(nums1[im] >= nums2[in]){
                nums1[id--] = nums1[im--];
            } else{
                nums1[id--] = nums2[in--];
            }
        }
        while(id>=0 && im>=0) nums1[id--] = nums1[im--];
        while(id>=0 && in>=0) nums1[id--] = nums2[in--];
    }
};