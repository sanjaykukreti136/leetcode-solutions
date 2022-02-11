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
    void check(TreeNode *root, vector<string>&v, string a)
    {
        if(root->left==NULL && root->right==NULL)
        {
            v.push_back(a+ to_string(root->val));
            return ;
        }
        if(root->left) check(root->left, v, a+ to_string(root->val)+ "->");
        if(root->right) check(root->right, v, a+to_string(root->val)+"->");
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> v;
        if(root==NULL) return v;
        check(root, v, "");
        return v;
    }
};