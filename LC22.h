class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        DFS(res, "", n, 1, 0, '(');
        return res;
        
    }
    
    void DFS(vector<string>& res, string str, int n, int lnum, int rnum, char c){
        if(lnum < rnum) return;
        else if(lnum == n && rnum == n){
            str += c;
            res.push_back(str);
            str.clear();
            return;
        } else if(c == '(' || c ==')'){
            str += c;
            if(lnum<n) DFS(res, str, n, lnum+1, rnum, '(');
            if(rnum<n) DFS(res, str, n, lnum, rnum+1, ')');
            return;
        }         
    }
};