class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int c=0;
        int s= 0 ;
        unordered_map<int,int>m;
        m[0] = 1;
        for(int i=0;i<nums.size();i++){
            s+= nums[i];
            int rem = s%k;
            if(rem < 0) rem+=k;
            if(m.find(rem)!=m.end()){
                
                c+= m[rem];
                m[rem]+=1;
            }else{
                m[rem] = 1;
            }
        }
        return c;
    }
};