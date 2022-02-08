class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n=nums.size();
        int left = nums[0];
        int l = -1;
        for(int i=1;i<n;i++){
            if(left  > nums[i]){
                l = i;
            }else{
                left = nums[i];
            }
        }
        int right = nums[n-1];
        int r=0;
        for(int i=n-2;i>=0;i--){
            if(nums[i] > right){
                r = i;
            }else{
                // nums[i] = right;
                right= nums[i];
            }
        }
        return l-r+1;
        
    }
};