class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        long long  left[n] , right[n];
        left[0] = 0;
        right[n-1] = 0;
        
        for(int i=1;i<nums.size();i++){
             left[i] = left[i-1] + i*(nums[i]-nums[i-1]);
        }
        
        for(int i=n-2;i>=0;i--){
            right[i] = right[i+1] + (n-i-1)*(nums[i+1]-nums[i]);
        }
        
        long long  ans= INT_MAX;
        for(int i=0;i<nums.size();i++){
            ans = min(ans, left[i]+right[i]);
        }
        return ans;
   }
};