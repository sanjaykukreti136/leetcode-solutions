class Solution {
public:
    
        void check(vector<int>nums, int idx , vector<vector<int>>&ans , vector<int>v, map<int,int>m){
        
        if(idx == nums.size()){
            ans.push_back(v);
            return ;
        }
        
        
            
        for(int i=0;i<nums.size();i++){
            if( m.find(nums[i])==m.end() ||  (m.find(nums[i])!=m.end()  && i>m[nums[i]]) ){
                    
                int prev = -1;
                if(m.find(nums[i])!=m.end()){
                    prev = m[nums[i]];
                }
                m[nums[i]] = i;
                v.push_back(nums[i]);
                check(nums, idx+1 , ans, v , m);
                v.pop_back();
                if(prev==-1) m.erase(nums[i]);
                else m[nums[i]] = prev;
                
            }   
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        map<int,int>m;
        vector<int>v;
        check(nums , 0 , ans, v, m);
        return ans;
    }
};