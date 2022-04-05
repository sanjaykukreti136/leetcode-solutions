class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        
        
        sort(nums.begin(), nums.end());
        int n = nums.size();
        return max( nums[0]*nums[1]*nums[n-1] ,  nums[n-1]*nums[n-2]*nums[n-3]  );
        
        // -6 -4 -2 0 2 4 6 
         
            // 48 
            // 6 * 4 * 6 = 63456
//         4 6 -6  = -
//         6 -6 -4 
        
        
            
        
    }
};