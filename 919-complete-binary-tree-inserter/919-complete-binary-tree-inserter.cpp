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
class CBTInserter {
public:
    TreeNode *head;
    queue<TreeNode*>q;
    CBTInserter(TreeNode* root) {
        head = root;
        q.push(root);
        while(!q.empty()){
            TreeNode *curr = q.front();
            if(curr->left && curr->right){
                q.pop();
                q.push(curr->left);
                q.push(curr->right);
                
            }else{
                if(curr->left) q.push(curr->left);
                break;
            }
        }
        
    }
    
    int insert(int val) {
        TreeNode *curr =q.front();
        if(curr->left==NULL){
            TreeNode *newnode = new TreeNode(val);
            curr->left = newnode;
            q.push(newnode);
            return curr->val;
        }else{
            TreeNode *newnode = new TreeNode(val);
            curr->right = newnode;
            q.pop();
            q.push(newnode);
            return curr->val;
        }
    }
    
    TreeNode* get_root() {
        return head;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */