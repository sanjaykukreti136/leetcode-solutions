class Solution {
public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map <int, int> ump;
        
        for(int i = 0; i < nums.size(); i++)
	{
            ump[nums[i]]++;
        }
        
        vector<vector<int>> bucket(nums.size()+1);
        for (auto [a, b] : ump){
            bucket[b].push_back(a);
        }
        
        vector <int> ans;
        for (int i = nums.size(); k; i--) {
            for (auto a : bucket[i]) {
                ans.push_back(a);
                k--;
            }
        }
        
        return ans;
    }
};