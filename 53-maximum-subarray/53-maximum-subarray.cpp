class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int s= 0;
        int ans= INT_MIN;
        for(int i=0;i<nums.size();i++){
            s+= nums[i];
            ans = max(s, ans);
            if(s<0){
                s = 0;
            }
        }
        return ans;
    }
};