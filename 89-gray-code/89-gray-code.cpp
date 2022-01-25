class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int>ans;
        ans.push_back(0);
        if(n == 0) return ans;
        ans.push_back(1);
        if(n==1) return ans;
        int curr = 1;
        for(int i=2;i<=n;i++){
            curr*= 2;
            for(int i=ans.size()-1;i>=0;i--){
                ans.push_back(curr + ans[i]);
            }
        }
        return ans;
        
    }
};