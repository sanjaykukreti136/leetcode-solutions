class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int x = 0;
        int ans = 0;
        while(x<=31){
            int c = 0;
            
            for(int i =0;i<nums.size();i++){
                if(nums[i]&(1<<x)){
                    c++;
                }
            }
            if(c%3!=0){
                // ans = ans<<x;
                ans = ans | (1<<x);
            }
            x++;
            
        }
        return ans;
    }
};