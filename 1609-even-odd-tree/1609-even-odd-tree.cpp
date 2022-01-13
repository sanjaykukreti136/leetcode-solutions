class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        if(!root) return true;
        int k=0;
        queue<TreeNode* > q;
        q.push(root);
        while(!q.empty())
        {
            int size=q.size();
            vector<int> v;
            while(size--)
            {
                auto node=q.front();
                q.pop();
                v.push_back(node->val);
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            if(k%2==0)
            {
                for(int i=0;i<v.size()-1;i++)
                {
                    if(v[i]%2==0) return false;
                    if(v[i]>=v[i+1]) return false;
                }
                if(v[v.size()-1]%2==0) return false;
            }
            else if(k%2==1)
            {
                for(int i=0;i<v.size()-1;i++)
                {
                    if(v[i]%2==1) return false;
                    if(v[i]<=v[i+1]) return false;
                }
                if(v[v.size()-1]%2==1) return false;
            }
            //v.clear();
            //flag!=flag;
            k++;
        }
        return true;
    }
};