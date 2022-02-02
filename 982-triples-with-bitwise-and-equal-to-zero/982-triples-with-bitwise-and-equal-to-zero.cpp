class Solution {
public:
    int countTriplets(vector<int>& nums) {
        unordered_map<int,int>m;
        for(auto i : nums){
            for(auto  j : nums) m[i&j]++;
        }
        int c=0;
        for(auto i : nums){
            for(auto j : m) if((i&j.first)==0) c+=j.second;
        }
        return c;
    }
};