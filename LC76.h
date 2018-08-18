class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size() < t.size()) return "";
        string res = "";
        int left = 0, cnt = 0, minLen = s.size()+1;
        unordered_map<char, int> mp;
        for(auto i: t) ++mp[i];
        for(int right = 0; right<s.size(); ++right){
            if(mp.find(s[right]) != mp.end()) {
                --mp[s[right]];
                if(mp[s[right]]>=0) ++cnt;
                while(cnt == t.size()){
                    if(right - left + 1 <minLen){
                        minLen = right - left + 1;
                        res = s.substr(left, minLen);
                    }
                    if(mp.find(s[left]) != mp.end()){
                        ++mp[s[left]];
                        if(mp[s[left]]>0) --cnt;
                    }
                    ++left;
                }                
            }
        }
        return res;
    }
};