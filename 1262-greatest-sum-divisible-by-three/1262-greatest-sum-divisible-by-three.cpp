class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int zero =0 , one = 0 , two = 0;
        for(auto i : nums){
            int idx = (zero + i)%3;
            int nzero =0, none = 0 , ntwo =0;
            if(idx == 0){
                nzero = max(nzero , zero + i);
            }else if(idx==1){
                none = max(none , zero+i);
            }else{
                ntwo = max(ntwo , zero+i);
            }
            
            idx = (one + i)%3;
            if(idx == 0){
                nzero = max(nzero , one + i);
            }else if(idx==1){
                none = max(none , one+i);
            }else{
                ntwo = max(ntwo , one+i);
            }
            
            idx = (two + i)%3;
            if(idx == 0){
                nzero = max(nzero , two + i);
            }else if(idx==1){
                none = max(none , two+i);
            }else{
                ntwo = max(ntwo , two+i);
            }
            
            one = max(one , none);
            two = max(two , ntwo);
            zero  =max(zero , nzero);
            cout<<zero<<" - "<<one<<" - "<<two<<"\n";
        }
        return zero;
    }
};