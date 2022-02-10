class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        int sum =0;
        int c=0;
        m[0] = 1;
        for(int i=0;i<nums.size();i++){
            sum+= nums[i];
            if(m.find(sum - k)!=m.end()){
                c+= m[sum-k];
            }
            if(m.find(sum)!=m.end()){
                m[sum]+=1;
            }else{
                m[sum] = 1;
            }
        }
        return c;
    }
};