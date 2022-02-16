class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        map<int,int>m;
        for(auto i : nums1) m[i]++;
        for(auto i : nums2){
            if(m.find(i)!=m.end()){
                ans.push_back(i);
                m.erase(i);
            }
            
        }
        return ans;
    }
};