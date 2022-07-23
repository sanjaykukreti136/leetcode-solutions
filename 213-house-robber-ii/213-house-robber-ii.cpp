class Solution {
public:
    int rob1(vector<int>& nums) {
        int inc = 0, exc = 0;
        for(auto i : nums){
            int t = i+exc;
            exc = max(inc , exc);
            inc = t;
        }
        return max(inc , exc);
    }
    int rob(vector<int>& nums) {
        vector<int>v1,v2;
        if(nums.size()==1) return nums[0];
        for(int i=0;i<nums.size()-1;i++){
            v1.push_back(nums[i]);
        }
        for(int i=1;i<nums.size();i++){
            v2.push_back(nums[i]);
        }
        return max(rob1(v1), rob1(v2));
    }
};