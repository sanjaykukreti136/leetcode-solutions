class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int val  = *max_element(nums.begin(), nums.end());
        
        int idx = -1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==val){
                idx = i;
            }else{
                if(val>=nums[i]*2){
                    
                }else{
                    return -1;
                }
            }
        }
        return idx;
        
    }
};