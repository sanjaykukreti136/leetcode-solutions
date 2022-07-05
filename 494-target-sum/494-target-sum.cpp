class Solution {
public:
    int c = 0;
    
    void check(vector<int>&nums , int t , int idx , int s){
        if(idx == nums.size()) {
            if(t==s) c++;
            return ;
        } ;
        check(nums , t , idx+1 , s+nums[idx]);
        check(nums , t , idx+1 , s-nums[idx]);
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        check(nums , target , 0 , 0);
        return c;
    }
};