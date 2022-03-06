class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        // map<int,TreeNode*>m;
        TreeNode *m[100007] ={ NULL };
        int a[100007] = {0};
        for(auto i : descriptions){
            int par = i[0];
            int child = i[1];
            a[child]= 1;
            int ind = i[2];
            
            TreeNode *ch= NULL;
            if(m[child]==NULL)  ch = new TreeNode(child);
            else ch = m[child];
            
            TreeNode *pa  =NULL;
            if(m[par]==NULL) pa= new TreeNode(par);
            else pa = m[par];
            
            if(ind ==1 ){
                pa->left = ch;
            }else{
                pa->right = ch;
            }
            m[child] = ch;
            m[par] = pa;
        }
        for(auto i : m){
            if(i!=NULL && a[i->val]==0) return i;
        }
        return NULL;
    }
};