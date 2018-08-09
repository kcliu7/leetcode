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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 0) return NULL;
        int pre_l = 0, in_l = 0, pre_r = preorder.size()-1, in_r = inorder.size()-1;        
        TreeNode *root = create(preorder, inorder, pre_l, pre_r, in_l, in_r);
        return root;
        
    }
    
    TreeNode* create(vector<int>& preorder, vector<int>& inorder, int pre_l, int pre_r, int in_l, int in_r){
        if(pre_l > pre_r || in_l > in_r) return NULL;
        TreeNode * root = new TreeNode(preorder[pre_l]);
        if(pre_l == pre_r) return root;
        int i = in_l;
        for(; i<= in_r; ++i){
            if(inorder[i] == preorder[pre_l]){
                break;
            }
        }
        int leftnum = i - in_l;
        root -> left = create(preorder, inorder, pre_l+1, pre_l+leftnum, in_l, in_l+leftnum-1);
        root -> right = create(preorder, inorder, pre_l+leftnum+1, pre_r, in_l+leftnum+1, in_r);
        return root;
    }
};