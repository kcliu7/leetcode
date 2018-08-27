class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> res;
        sort(nums.begin(), nums.end());
        for(int k = 0; k < nums.size(); ++k){
            if(nums[k] > 0) break;
            int target = 0 - nums[k];
            int i = k + 1, j = nums.size() - 1;
            while(i < j){
                if(target == nums[i] + nums[j]){
                    res.insert({nums[k], nums[i], nums[j]});
                    while(i<j && nums[i] == nums[i+1]) ++i;
                    while(i<j && nums[j] == nums[j-1]) --j;
                    ++i, --j;
                } else if(target > nums[i] + nums[j]){
                    ++i;
                } else --j;
            }
        }
        return vector<vector<int>> (res.begin(), res.end());
    }
};