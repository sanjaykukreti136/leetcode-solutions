class Solution {
public:
    vector<vector<int>>ans;
    set<vector<int>>st;
    void check(int idx , vector<int>&nums , vector<int>&v , int prev){
        if(idx == nums.size()){
            if(v.size()>=2){
                // ans.push_back(v);
                st.insert(v);
            }
            return ;
        }
        
        if(nums[idx] >= prev){
            v.push_back(nums[idx]);
            check(idx+1 , nums , v , nums[idx]);
            v.pop_back();
        }
        check(idx+1 , nums  , v , prev);
        
    }
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        
        
        for(int i=0;i<nums.size();i++){
            vector<int>v;
            v.push_back(nums[i]);
            check(i+1 , nums , v , nums[i]);
        }
        for(auto i : st){
            ans.push_back(i);
        }
        return ans;
    }
};