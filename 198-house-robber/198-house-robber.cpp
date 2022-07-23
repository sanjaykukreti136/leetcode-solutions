class Solution {
public:
    int rob(vector<int>& nums) {
        int inc = 0, exc = 0;
        for(auto i : nums){
            int t = i+exc;
            exc = max(inc , exc);
            inc = t;
        }
        return max(inc , exc);
    }
};