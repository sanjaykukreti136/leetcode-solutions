class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>>ans;
        vector<int>temp = { 1 };
        ans.push_back(temp);
        for(int i=2;i<=n;i++){
            vector<int>t; 
            t.push_back(1);
            for(int j=1;j<ans[i-2].size();j++){
                t.push_back(ans[i-2][j-1] + ans[i-2][j]);
            }
            t.push_back(1);
            ans.push_back(t);
        }
        return ans;
    }
};