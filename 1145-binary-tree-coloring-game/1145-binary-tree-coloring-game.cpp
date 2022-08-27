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
    int lc = 0;
    int rc = 0;
    int check(TreeNode *root , int x){
        if(!root ) return 0;
        int l = check(root->left , x);
        int r  = check(root->right ,x );
        if(root->val ==x){
            lc = l;
            rc = r;
        }
        return l+r+1;
    }
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        check(root , x);
        int up = n - (lc+rc+1);
        int v = max(max(lc,rc) , up);
        if(v > (n/2)) return true;
        return false;
    }
};