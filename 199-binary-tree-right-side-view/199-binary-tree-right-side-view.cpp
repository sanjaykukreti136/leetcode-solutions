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
    vector<int> rightSideView(TreeNode* root) {
        vector<int>res;
        queue<TreeNode *>q;
        if(!root) return res;
        q.push(root);
        q.push(NULL);
        
        while(!q.empty()){
            TreeNode *curr = q.front();
            q.pop();
            if(curr){
                if(q.front()==NULL){
                    res.push_back(curr->val);
                }
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            else if(q.size()!=0){
                q.push(NULL);
            }
            
            
        }
        return res;
        
    }
};