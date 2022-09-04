class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int i=0, j=0;
        while(j<nums.size()){
            if(nums[j]%2==0 && nums[i]%2!=0){
                swap(nums[i], nums[j]);
                j++;
            }else{
                j++;
            }
            if(nums[i]%2==0) i++;
        }
        return nums;
    }
};