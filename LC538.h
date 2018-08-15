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
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        helper(root, sum);
        return root;
    }
    
    void helper(TreeNode* &root, int & sum){
        if(root==NULL) return;
        helper(root->right, sum);
        root->val += sum;
        sum = root-> val;
        helper(root->left, sum);
    }
    
    
};