class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = 0, j = 0;
        j = nums.size()-2;
        while(j>=0 && nums[j]  >= nums[j+1]) j--;
        if(j>=0){
        i = nums.size()-1;
        while(i>=0 && nums[i] <= nums[j]) i--;
        // if(i<j) return ;
        swap(nums[i], nums[j]);
        }
        i=j+1;
        j = nums.size()-1;
        while(i<j){
            swap(nums[i], nums[j]);
            i++;
            j--;
        }
    }
};