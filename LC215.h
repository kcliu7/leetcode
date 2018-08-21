class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0, right = nums.size() - 1;
        while(true){
            int a =  partition(nums, left, right);
            if(a == k-1) return nums[k-1];
            if(a > k-1) right = a - 1;
            else left = a + 1;
        }
    }
    int partition(vector<int>& nums, int lh, int rh){
        int tmp = nums[lh];
        while(lh < rh){
            while(lh<rh && nums[rh] < tmp) --rh;
            nums[lh] = nums[rh];
            while(lh<rh && nums[lh] >= tmp) ++lh;
            nums[rh] = nums[lh];           
        }
        nums[lh] = tmp;
        return lh;
    }
};