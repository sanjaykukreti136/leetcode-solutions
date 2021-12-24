class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = INT_MIN;
        int s = 1;
        for(int i=0;i<nums.size();i++){
            s*= nums[i];
            ans = max(ans , s);
            if(s==0){
                s = 1;
            }
        }
        s = 1;
        for(int i = nums.size()-1;i>=0;i--){
            s*= nums[i];
            ans = max(ans , s);
            if(s==0){
                s = 1;
            }
        }
        return ans;
    }
};