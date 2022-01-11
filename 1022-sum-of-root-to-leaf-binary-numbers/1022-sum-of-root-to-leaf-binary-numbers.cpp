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
    int ans =0;
    int binaryToDecimal(string n)
{
    string num = n;
    int dec_value = 0;
 
    // Initializing base value to 1, i.e 2^0
    int base = 1;
 
    int len = num.length();
    for (int i = len - 1; i >= 0; i--) {
        if (num[i] == '1')
            dec_value += base;
        base = base * 2;
    }
 
    return dec_value;
}
    void check(TreeNode *root , string c){
        if(!root){
            // string x = to_string(c);
            
            return ;
        }
        
        if(!root->left && !root->right){
            c+= to_string(root->val);
            cout<<c<<" ";
            int t = binaryToDecimal(c);
            cout<<t<<" \n";
            ans+=t;
        }
        
        check(root->left, c+to_string(root->val));
        check(root->right, c+to_string(root->val));
    }
    int sumRootToLeaf(TreeNode* root) {
        check(root , "");
        return ans;
    }
};