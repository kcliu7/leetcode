/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    string tree2str(TreeNode* t) {
        if(t == NULL) return "";
        string res = "";
        helper(t, res);
        return string(res.begin()+1, res.end()-1);
    }
    
    void helper(TreeNode* t, string& res){
        if(!t) return;
        res += "(" + to_string(t->val);
        if(!t->left && t->right) res+="()";
        helper(t->left, res);
        helper(t->right, res);
        res += ")";
    }
};