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
    bool isEvenOddTree(TreeNode* root) {
        if(!root) return false;
        queue<TreeNode *>q;
        q.push(root);

        int lev = 0;
        while(!q.empty()){
            int x = q.size();
            int prev = -1;
            while(x--){
                TreeNode *t = q.front();
                q.pop();
                if(lev%2==0){
                    if((prev!=-1 && t->val<=prev ) || (t->val%2==0) ) return false;
                }else{
                    if(prev!=-1 && t->val>=prev || (t->val%2!=0) ) return false;
                }
                prev = t->val;
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            }
            lev+=1;
        }
        return true;
        
    }
};