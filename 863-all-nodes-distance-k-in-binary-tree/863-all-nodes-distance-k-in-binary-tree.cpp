/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    void check(TreeNode *root , unordered_map<TreeNode*, TreeNode*>&m){
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode *t = q.front();
            q.pop();
            if(t->left){
                m[t->left] = t;
                q.push(t->left);
            }
            if(t->right){
                m[t->right] = t;
                q.push(t->right);
            }
        }
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>parent;
        check(root , parent);
        
        queue<TreeNode*>q;
        unordered_map<TreeNode*,bool>vis;
        q.push(target);
        vis[target] = true;
        int lev= 0;
        while(!q.empty()){
            int size = q.size();
            if(lev++==k) break;
            while(size--){
                TreeNode *t = q.front();
                q.pop();
                if(t->left && !vis[t->left]){
                    vis[t->left] = true;
                    q.push(t->left);
                }
                if(t->right && !vis[t->right]){
                    vis[t->right] = true;
                    q.push(t->right);
                }
                if(parent[t] && !vis[parent[t]] ){
                    vis[parent[t]] = true;
                    q.push(parent[t]);
                }
            }
        }
        vector<int>ans;
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};