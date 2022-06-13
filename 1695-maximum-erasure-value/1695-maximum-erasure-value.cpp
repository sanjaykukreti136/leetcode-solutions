class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int res = 0, maxres = 0;
        int start = 0, end = 0;
        int len = nums.size();
        unordered_map<int, int> map;
        
        while(end < len) {
            map[nums[end]]++;
            res = res + nums[end];
            while(map[nums[end]] > 1) {
                res = res - nums[start];
                map[nums[start]]--;
                
                if(map[nums[start]] == 0)
                    map.erase(nums[start]);
                
                start++;
            }
            maxres = max(maxres, res);
            end++;
        }
        
        return maxres;
    }
};