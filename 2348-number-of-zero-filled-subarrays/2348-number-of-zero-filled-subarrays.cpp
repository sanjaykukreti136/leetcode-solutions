class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
               long long  int a=nums.size(),ans=0,sta=0;
            for(int i=0;i<a;i++)
            {
                    if (nums[i]==0) ans++; 
                    else {
                    sta+=(ans*(ans+1))/2;
                        ans=0;
                    }
            }
            sta+=(ans*(ans+1))/2;//** **most imp. and overlooked part**.**
            return sta;
    }
};