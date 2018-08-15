class Solution {
public:
    int countBinarySubstrings(string s) {
        int cnt = 0;
        int n = s.size();
        for(int i = 0; i < n-1; ++i){
            int left = i;
            int right = i+1;
            if(s[left] == s[right]) continue;
            ++cnt; --left; ++right;
            while(left>=0 && right<n &&s[left]==s[left+1] && s[right] == s[right-1]){
                ++cnt; --left; ++right;
            }
        }
        return cnt;
    }
};