class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int val = nums[0];
        int c= 0;
        for(auto i : nums){
            if(i==val){
                c++;
            }else{
                c--;
            }
            if(c == 0){
                c = 1;
                val = i;
            }
        }
        c = 0;
        for(auto i : nums){
            if(i==val) c++;
        }
        int n = nums.size();
        if(c>=n/2) return val;
        return -1;
    }
};