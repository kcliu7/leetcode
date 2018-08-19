class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int lh = 0, rh = nums.size()-1;
        return helper(nums, lh, rh);
    }
    
    int helper(vector<int>& nums, int lh, int rh){
        if(lh >= rh) return nums[lh];
        int mid = lh + (rh - lh) / 2;
        int maxLeft = helper(nums, lh, mid-1);
        int maxRight = helper(nums, mid+1, rh);
        int mmax = nums[mid], t = mmax;
        for(int i=mid-1; i>=lh; --i){
            t += nums[i];
            mmax = max(mmax, t);
        }
        t = mmax;
        for(int i = mid+1; i<=rh; ++i){
            t += nums[i];
            mmax = max(mmax, t);
        }
        return max( mmax, max( maxLeft, maxRight ) ) ;
    }
};