class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long ans = 1 , c=1;
        for(int i=1;i<prices.size();i++){
            if(prices[i] == prices[i-1]-1){
                
                c++;
                ans+=c;
            }else{
                c =1;
                ans+=c;
            }
        }
        // ans+=c;
        return ans;
    }
};