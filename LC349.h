class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        unordered_map<int, int> cnt;
        vector<int> res;
        for(auto i : nums1) ++mp[i];
        for(auto i : nums2){
            if(cnt[i] > 0 || mp.find(i)==mp.end()) continue;
            res.push_back(i);
            ++cnt[i];
        }
        return res;
    }
};