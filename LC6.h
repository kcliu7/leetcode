class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows <= 1) return s;
        int zigzag = 2 * numRows - 2;
        string ans;
        for(int i=0; i<numRows; ++i){
            for(int j=i; j<s.size(); j+=zigzag){
                ans.append(1, s[j]);
                int ti = j+zigzag-2*i;
                if(i!=0 && i!=numRows-1 && ti <s.size()){
                    ans.append(1, s[ti]);
                }
            }
        }
        return ans;
    }
};