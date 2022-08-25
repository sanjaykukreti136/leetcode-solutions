class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int>left(n,  0);
        vector<int>right(n,0);
        int leftmin = prices[0];
        int rightmax = prices[n-1];
        for(int i=1;i<n;i++){
            left[i] = max(left[i-1] , prices[i]-leftmin );
            leftmin = min(leftmin  , prices[i]);
        }
        for(int i=n-2;i>=0;i--){
            right[i] = max(right[i+1] , rightmax- prices[i] );
            rightmax = max(rightmax , prices[i]);
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            ans = max(ans , left[i]+ right[i]);
        }
        return ans;
        
    }
};