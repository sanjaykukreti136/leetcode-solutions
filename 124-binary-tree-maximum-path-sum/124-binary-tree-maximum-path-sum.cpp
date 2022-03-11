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
    int ans = INT_MIN;
    int check(TreeNode *root){
        if(!root) return INT_MIN;
        if(!root->left && !root->right){
            ans = max(ans , root->val);
            return root->val;
        }
        int l = check(root->left);
        int r = check(root->right);
        l = l<0 ? 0 : l;
        r = r<0 ? 0 : r;
        ans = max(ans , l + r + root->val);
        ans = max(ans , l + root->val);
        ans = max(ans , r + root->val);
        return max(l,r) + root->val;
    }
    int maxPathSum(TreeNode* root) {
        ans = max(ans , check(root));
        return ans;
    }
};