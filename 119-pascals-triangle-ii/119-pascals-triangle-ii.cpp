class Solution {
public:
    vector<int> getRow(int n) {
        vector<int>ans;
        long val = 1;
        ans.push_back((int)val);
        for(int i=0;i<n;i++){
            val = (val*(n-i))/(i+1);
            ans.push_back((int)val);
        }
        return ans;
    }
};