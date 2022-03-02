class Solution {
public:
    int search(vector<int>& nums, int t) {
        int i=0, j= nums.size()-1;
        while(i<=j){

            int mid  = (i+j)/2;
            if(nums[mid]==t) return mid;
            
            if(nums[i] <= nums[mid]){
                if(t>=nums[i] && t<=nums[mid]) j = mid-1;
                else{
                    i = mid+1;
                }
            }else if(nums[mid]<=nums[j]){
                if(t>=nums[mid] && t<=nums[j]) i = mid+1;
                else{
                    j = mid-1;
                }
            }
        }
        return -1;
    }
};