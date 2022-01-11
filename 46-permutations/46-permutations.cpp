class Solution {
public:
    
    void check(vector<int>nums, int idx , vector<vector<int>>&ans , vector<int>v){
        
        if(idx == nums.size()){
            ans.push_back(v);
            return ;
        }
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=INT_MAX){
                int x = nums[i];
                v.push_back(nums[i]);
                nums[i] = INT_MAX;
                check(nums, idx+1 , ans , v);
                v.pop_back();
                nums[i] = x;
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>v;
        check(nums , 0 , ans, v);
        return ans;
    }
};