class Solution {
public:
    
    void check(vector<vector<int>>&ans, vector<int>nums, int i , int j){
        if(i==j-1){
            ans.push_back(nums);
            return ;
        }
        
        for(int k=i;k<j;k++){
            if(i!=k && nums[i]==nums[k]) continue;
            swap(nums[i], nums[k]);
            check(ans, nums, i+1 , j);
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        // vect
        sort(nums.begin(), nums.end());
        check(ans , nums , 0 , nums.size());
        return ans;
    }
};