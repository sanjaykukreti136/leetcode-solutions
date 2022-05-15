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
    int deepestLeavesSum(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        int s=0;
        int ans= root->val;
        while(!q.empty()){
            TreeNode* temp= q.front();
            q.pop();
            if(temp){
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
                if(!temp->left && !temp->right){
                    s+= temp->val;
                }
            }
            else{
                if(!q.empty()){
                    q.push(NULL);
                }
                ans= s;
                s=0;
            }
        }
        return ans;
    }
};