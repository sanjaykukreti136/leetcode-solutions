class Solution {
public:
    
    void check(vector<int>nums, vector<vector<int>>&ans, vector<int>v , int idx, string s){
        
        if(s == "f"){
            ans.push_back(v);
            return ;
        }
        
        check(nums, ans, v, idx, "f");
        int prev =-1;
        for(int i=idx;i<nums.size();i++){
            if(prev!=-1 && nums[i]==prev ) continue;
            else{
                v.push_back(nums[i]);
                check(nums, ans , v , i+1 , "t");
                v.pop_back();
            }
            prev = nums[i];
        }
        
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(), nums.end());
        vector<int>v;
        check(nums, ans , v , 0 , "n");
        return ans;
    }
};