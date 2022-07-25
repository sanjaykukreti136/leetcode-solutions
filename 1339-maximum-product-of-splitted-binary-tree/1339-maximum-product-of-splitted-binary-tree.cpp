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

#define ll long long 
class Solution {
public:
    long long total =0, ans = 0;
    int check1(TreeNode *root){
       if(!root) return 0;
        return root->val + check1(root->left) + check1(root->right);
    }
    
    int check(TreeNode *root){
        if(!root) return 0;
        ll l = check(root->left);
        ll r = check(root->right);
        ll up  = total - l-r-root->val;
        ll a = up*(l + r + (long long)root->val);
        ll b = l*(r + up + (long long)root->val);
        ll c = r*(l + up + (long long)root->val);
        ans = max( max( max(ans , a) , b ),c );
        return l+r+root->val;
    }
    
    int maxProduct(TreeNode* root) {
       total =  check1(root); 
       check(root);
        return ans%1000000007;
    }
};