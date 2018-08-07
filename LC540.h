class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int lh = 0, rh = nums.size() - 1, mid;
        while(lh < rh){
            mid = lh + (rh - lh) / 2;
            if(nums[mid] == nums[mid+1]){
                if(mid % 2 == 0){
                    lh = mid + 2;
                } else{
                    rh = mid - 1;
                }
            } else{
                if(mid == 0 || nums[mid] != nums[mid-1]) return nums[mid];
                if(mid % 2 == 0){
                    rh = mid - 2;
                } else{
                    lh = mid + 1;
                }
            }
        }
        return nums[lh];
    }
    
};