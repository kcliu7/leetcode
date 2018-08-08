class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int size = nums.size();  
        int a;        
        bool flag = false;        
        for(int i = 0; !flag && i < size; ++i){
            a = nums[i];
            for(int j = i+1; j<size; ++j ){
                a += nums[j];
                if(a == k || k!=0 && a % k == 0){
                    flag = true;
                    break;
                }
            }
        }
        return flag;        
    }    
};