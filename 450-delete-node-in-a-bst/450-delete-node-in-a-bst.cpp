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
    
    TreeNode *check(TreeNode *root , int k){
        if(!root) return root;
        if(root->val > k){
            root->left = check(root->left , k);
        }
        else if(root->val < k){
            root->right = check(root->right , k);
        }
        else{
            if( root->right){
                TreeNode *curr = root->right;
                while(curr->left){
                    curr = curr->left;
                }
                root->val = curr->val;
                root->right =  check(root->right , curr->val );
                return root;
            }
            else if(root->left){
                return root->left;
            }
            else if(!root->left && !root->right) return NULL;
        }
        return root;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        return check(root, key);
    }
};