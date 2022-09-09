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
    
    pair<bool,int> check(TreeNode *root){
        if(!root) return { true , 0 };
        
        pair<bool , int>l = check(root->left);
        pair<bool,int>r = check(root->right);
        bool ans = abs(l.second-r.second)<=1 ? true  : false;
        ans = ans && l.first && r.first;
        pair<bool,int>res = { ans , max(l.second , r.second)+1  };
        return res;
    }
    
    bool isBalanced(TreeNode* root) {
        pair<bool,int>p = check(root);
        return p.first;
    }
};