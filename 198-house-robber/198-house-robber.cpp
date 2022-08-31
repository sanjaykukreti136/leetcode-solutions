class Solution {
public:
    int rob(vector<int>& nums) {
        int inc = 0, exc = 0;
        for(auto i : nums){
            int t = inc;
            inc = exc + i;
            exc = max(exc , t);
        }
        return max(inc , exc);
    }
};