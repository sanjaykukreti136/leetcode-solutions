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
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*>q;
        q.push(root);
        int a = 0, b = 0;
        while(!q.empty()){
            int x1 = q.size();
            while(x1--){
                TreeNode *curr= q.front();
                q.pop();
                if(curr->left && (curr->left->val==x || curr->left->val==y)){
                    a+= curr->left->val;
                    continue;
                }else if(curr->left){
                    q.push(curr->left);
                }
                if(curr->right && (curr->right->val==x || curr->right->val==y)){
                    a+= curr->right->val;
                }else if(curr->right){
                    q.push(curr->right);
                }                
                
            }
            
            if(a!=0){
                if(a!=x+y) return false;
                return true;
            }
            
        }
        return false;
    }
};