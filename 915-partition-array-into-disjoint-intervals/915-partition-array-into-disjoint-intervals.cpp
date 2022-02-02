class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int lmax = nums[0];
        int pmax = nums[0];
        int ans = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>=lmax){
                lmax = nums[i];
            }
            else if(nums[i]<pmax){
                ans = i;
                pmax = lmax;
            }
        }
        return ans+1;
    }
};