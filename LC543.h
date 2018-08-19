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
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root ) return 0;
        int res = height(root->left) + height(root->right);
        return max(res, max(diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right)));
    }
    
    int height(TreeNode* root){
        if(!root) return 0;
        if(m.count(root) ) return m[root];
        int h = 1 + max(height(root->left), height(root->right) );  
        return m[root] = h;
    }
    
private:
    unordered_map<TreeNode*, int> m;
};