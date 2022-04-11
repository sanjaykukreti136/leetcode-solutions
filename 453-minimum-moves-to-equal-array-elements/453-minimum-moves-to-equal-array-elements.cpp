class Solution {
public:
    int minMoves(vector<int>& nums) {
        int sum=0;
        for(auto i:nums)
            sum+=i;
        if(nums.size())
            return sum - (*min_element(nums.begin(),nums.end()))*nums.size();
        return 0;
    }
};