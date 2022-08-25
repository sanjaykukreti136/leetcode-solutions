
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return root;
        invertTree(root->left);
        invertTree(root->right);
        // INTERCHANGE ROOT LEFT AND RIGHT IN POSTORDER
        TreeNode *l= root->left;
        TreeNode *r= root->right;
        root->left = r;
        root->right = l;
        return root;
    }
};