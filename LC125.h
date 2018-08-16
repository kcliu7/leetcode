class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        int lh = 0, rh = n - 1;
        while(lh < rh){
            if( !helper(s, lh) ){
                ++lh; continue;
            } else if( !helper(s, rh) ){
                --rh; continue;
            }
            if(s[lh] != s[rh]) return false;
            ++lh; --rh;
        }
        return true;
    }
    
    bool helper(string & s, int i){
        if(s[i] <= '9' && s[i] >= '0' || s[i] <= 'z' && s[i] >= 'a') return true;
        if(s[i] <= 'Z' && s[i] >= 'A'){
            s[i] += 'a' -'A';
            return true;
        }
        return false;
    }
};