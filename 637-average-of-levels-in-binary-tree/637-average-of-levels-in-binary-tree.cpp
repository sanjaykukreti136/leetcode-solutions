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
    double calcAvg(vector<int>&v)
    {
        double sum=0.00;
        int n=v.size();
        for(int i=0;i<n;i++)
        {
            sum+=v[i];
        }
        cout<<sum<<"\n";
        return (sum/(double)n);
    }
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        if(!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            int size=q.size();
            vector<int> v;
            for(int i=0;i<size;i++)
            {
                auto node= q.front();
                q.pop();
                v.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            double avg=calcAvg(v);
            res.push_back(avg);
        }
        return res;
    }
    
};