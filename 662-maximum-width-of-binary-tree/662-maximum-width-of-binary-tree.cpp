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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int ans = 0;
        int last , first;
        queue<pair<TreeNode*,long long>>q;
        q.push({root , 0});
        while(!q.empty()){
            int size = q.size();
            int minv = q.front().second;
            for(int i =0;i<size;i++){
                TreeNode *t = q.front().first;
                long long  id = q.front().second - minv ;
                q.pop();
                if(i==0) first = id;
                if(i==size-1) last = id;
                if(t->left){
                    q.push({t->left , 2*id+1});
                }
                if(t->right){
                    q.push({t->right , 2*id+2});
                }
            }
            ans = max(ans , last-first+1);
        }
        return ans;
    }
};