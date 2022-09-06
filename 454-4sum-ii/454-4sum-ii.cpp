class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        map<int,int>m;
        for(auto i : nums1){
            for(auto j : nums2){
                m[i+j]++;
            }
        }
        int c=0;
        for(auto i : nums3){
            for(auto j : nums4){
                c+=m[-(i+j)];
            }
        }
        return c;
    }
};