class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int>m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]] = i;
        }
        
        for(int i=0;i<nums.size();i++){
            if(m.find(target - nums[i])!=m.end() && m[target-nums[i]]!=i ){
                 vector<int>v = { i , m[target-nums[i]] };
                return v;
            }
        }
         vector<int>v =  { };
        return v;
    }
};