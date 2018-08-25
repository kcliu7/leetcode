class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i = 0; i < s.size(); ++i){
            char c = s[i];
            if(c=='(' || c=='[' || c=='{'){
                st.push(c);
            } else if( c==')' || c==']' || c=='}' ){
                if(st.empty()) return false;
                else if( c==')' ){
                    if(st.top() != '(') return false;
                    st.pop();
                } else if( c==']' ){
                    if(st.top() != '[') return false;
                    st.pop();
                } else if( c=='}' ){
                    if(st.top() != '{') return false;
                    st.pop();
                }
            }
        }
        if(!st.empty() ) return false;
        return true;
    }
};