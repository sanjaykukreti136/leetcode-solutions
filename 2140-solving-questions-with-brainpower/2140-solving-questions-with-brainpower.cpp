class Solution {
public:
    long long mostPoints(vector<vector<int>>& v) {
        int n = v.size();

        vector<long long>a(n , 0);
        long long  ans = 0;
        for(int i=v.size()-1;i>=0;i--){
            if(i+v[i][1] + 1>=n){
                a[i] = v[i][0];

            }else{
                a[i] = v[i][0] + a[i+v[i][1] + 1];
              
            }
            
           if(i+1 < n ) a[i] = max(a[i] , a[i+1]);
            ans = max(ans , a[i]);
            
        }
        return ans;
    }
};