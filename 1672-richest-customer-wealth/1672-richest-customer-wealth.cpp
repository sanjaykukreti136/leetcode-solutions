class Solution {
public:
    int maximumWealth(vector<vector<int>>& v) {
        int ans =0;
        for(auto i : v){
            int s =0;
            for(auto j : i) s+=j;
            ans = max(ans , s);
        }
        return ans;
    }
};