class Solution {
public:
    int calculate(string s) {
        int res = 0, num = 0, sign = 1;
        stack<int> st;
        for(int i = 0; i<s.size(); ++i){
            char c = s[i];
            if(c>='0' && c<='9'){
                num = num * 10 + c - '0';
            } else if(c == '+' || c == '-'){
                res += num * sign;
                num = 0;
                sign = (c == '+') ? 1 : -1;
            } else if(c == '(' ){
                st.push(res);
                st.push(sign);
                res  = 0;
                sign = 1;
            } else if(c == ')' ){
                res += sign * num;
                num = 0;
                res *= st.top(); st.pop();
                res += st.top(); st.pop();
            }
        }
        res += num * sign; 
        return res;
    }
};