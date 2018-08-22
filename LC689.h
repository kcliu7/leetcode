class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size(), mx = INT_MIN;
        vector<int> res, sum{0}, left(n,0), right(n, n-k);
        for(auto num: nums) sum.push_back(sum.back() + num);
        for(int i = k, total = sum[k]-sum[0]; i<n; ++i){
            if(sum[i+1] - sum[i+1-k] > total){
                total = sum[i+1] - sum[i+1-k];
                left[i] = i - k + 1;
            }
            else left[i] = left[i-1];
        }
        
        for(int i = n-k-1, total = sum[n] - sum[n-k]; i>=0; --i){
            if(sum[i+k] - sum[i] >= total){
                total = sum[i+k] - sum[i];
                right[i] = i;
            } else{
                right[i] = right[i+1];
            }
        }
        
        for(int i = k; i<= n - 2*k; ++i){
            int l = left[i-1], r = right[i+k];
            int total = sum[i+k] - sum[i] + (sum[l + k] - sum[l]) + (sum[r + k] - sum[r]);
            if(mx < total){
                mx = total;
                res = {l, i, r};
            }            
        }
        return res;
    }
};