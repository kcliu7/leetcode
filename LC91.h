class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() || s.front() == '0') return 0;
        int c1 = 1, c2 = 1;
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == '0') c1 = 0;
            if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6')) {
                c1 = c1 + c2;
                c2 = c1 - c2;
            } else {
                c2 = c1;
            }
        }
        return c1;
    }
};