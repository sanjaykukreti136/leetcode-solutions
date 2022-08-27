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
    //pair of profit in {choose,not choose} case will be returned
    pair<int,int> calc(TreeNode* root)
    {
        //if null then profit will be 0 in both case
        if(!root)
            return {0,0};
        int choose , not_choose;
        //get the profits from left subtree
        pair<int,int>l=calc(root->left);
        //get the profits from right subtree
        pair<int,int>r=calc(root->right);
        //if we choose the root to be in our robbery then we will not consider the choose's case from both the children ..hence root' value plus the not choosen cases are added
        choose=root->val+l.second+r.second;
        //if we do not rob the root then we will add the max from left and right subtree
        not_choose=max(l.first,l.second)+max(r.first,r.second);
        return {choose,not_choose};
    }
    
    int rob(TreeNode* root) {
        pair<int,int>p=calc(root);
        //even root will given profit of choosing root and not choosing root hence we will return max of both the cases
        return max(p.first,p.second);
    }
};