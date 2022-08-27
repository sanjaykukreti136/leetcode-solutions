/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    void check1(TreeNode*curr){
        if(!curr) return ;
        if(curr->left && curr->left->val==-1001){
            curr->left = NULL;
        }
        if(curr->right && curr->right->val==-1001){
            curr->right = NULL;
        }
        check1(curr->left);
        check1(curr->right);
    }
    string t = "";
    void check(TreeNode *root){
        if(!root){
            t+=".,";
            return ;
        }
        t+=to_string(root->val)+",";
        check(root->left);
        check(root->right);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        check(root);
        cout<<t<<"\n";
        return t;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string s) {
        TreeNode *root = NULL;
        stack<TreeNode *>st;
        for(int i=0;i<s.size();){
            string temp  = "";
            while(s[i]!=','){
                temp+=s[i++];
            }
            if(temp=="."){
                TreeNode *curr = new TreeNode(-1001);
                if(st.empty()){
                }else{
                    if(st.top()->left==NULL){
                        st.top()->left = curr;
                    }else{
                        if(st.top()->right==NULL){
                            st.top()->right = curr;
                            st.pop();
                        }
                    }
                }
                i+=1;
                
                
            }
            else{
                cout<<temp<<"\n";
                int n = stoi(temp);
                TreeNode *curr = new TreeNode(n);
                if(st.empty()){
                    st.push(curr);
                    root = curr;
                }else{
                    if(st.top()->left==NULL){
                        st.top()->left = curr;
                        st.push(curr);
                    }else{
                        if(st.top()->right==NULL){
                            st.top()->right = curr;
                            st.pop();
                        }
                        st.push(curr);
                    }
                }
                i+=1;
                
            }
            
        }
        
        TreeNode *curr = root;
        check1(curr);
        
        return root;
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));