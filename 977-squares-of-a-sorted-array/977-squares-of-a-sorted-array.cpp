class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
         vector<int>ans;
        int i = 0 , j = nums.size()-1;
        while(i<=j){
            if(nums[i]*nums[i] > nums[j]*nums[j]){
                ans.push_back(nums[i]*nums[i]);
                i++;
            }else{
                ans.push_back(nums[j]*nums[j]);
                j--;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};