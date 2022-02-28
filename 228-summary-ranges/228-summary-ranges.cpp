class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ret;
        int i=0;
        while(i<nums.size()){
            int j=i;
            while(j<nums.size()-1 && nums[j]==nums[j+1]-1){
                j++;
            }
            if(i==j){
                ret.emplace_back(to_string(nums[i]));
                i++;
            }else{
                ret.emplace_back(to_string(nums[i])+"->"+to_string(nums[j]));
                i=j+1;
            }
        }
        return ret;
    }
};