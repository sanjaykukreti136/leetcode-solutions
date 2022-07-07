/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode *pre  = NULL;
    bool check(TreeNode* root){
        if(root==NULL) return true;
        if(check(root->left )==false) return false;
        if(pre && root->val <= pre->val ) return false;
        pre = root;
        if(check(root->right )==false) return false;
        return true;
    }
    bool isValidBST(TreeNode* root) {
        if(root && !root->left && !root->right) return true;
        return check(root);
        
    }
};