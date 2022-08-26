struct NodeInfo {
    bool isBST;
    int sum;
    int mini;
    int maxi;
    
    NodeInfo(bool isBST, int sum, int mini, int maxi) : isBST(isBST), sum(sum), mini(mini), maxi(maxi) {}
};

class Solution {
private:
    NodeInfo solve(TreeNode* root, int& ans) {
        if (!root) {
            return NodeInfo(true, 0, INT_MAX, INT_MIN);
        }
        NodeInfo left = solve(root->left, ans);
        NodeInfo right = solve(root->right, ans);
        
        NodeInfo cur(false, root->val + left.sum + right.sum, min(root->val, min(left.mini, right.mini)), 
                                                              max(root->val, max(left.maxi, right.maxi)));
        if (left.isBST && right.isBST && (left.maxi < root->val && right.mini > root->val)) {
            cur.isBST = true;
            ans = max(ans, cur.sum);
        }
        return cur;
    }
public:
    int maxSumBST(TreeNode* root) {
        int ans = 0;
        solve(root, ans);
        return ans;
    }
};