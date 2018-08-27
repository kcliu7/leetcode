class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>> res;
        sort(nums.begin(), nums.end());        
        for(int m = 0; m < int( nums.size() - 3); ++m){
            for(int n = m+1; n<int(nums.size() - 2); ++n){
                //if(n>m+1 && nums[n] == nums[n-1]) continue; 
                int i = n+1, j = nums.size()-1;
                while(i < j){
                    if(nums[m] + nums[n] + nums[i] + nums[j] == target){
                        res.insert({nums[m], nums[n], nums[i], nums[j]});
                        ++i, --j;
                    } else if(nums[m] + nums[n] + nums[i] + nums[j] > target){
                        --j;
                    } else ++i;
                }
            }
        }
        return vector<vector<int>>(res.begin(), res.end());       
        
    }
};