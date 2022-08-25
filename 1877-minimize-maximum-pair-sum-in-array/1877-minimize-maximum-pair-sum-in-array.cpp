class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = 0;
        int i = 0, j = nums.size()-1;
        while(i<j){
            res = max(res , nums[i] + nums[j]);
            i++;
            j--;
        }
        return res;
    }
};