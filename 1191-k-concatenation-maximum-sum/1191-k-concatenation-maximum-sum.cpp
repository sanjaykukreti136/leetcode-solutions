class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        vector<int>ans;
        
        long a =0, s=0;
        int m = 1000000007;
        
        int n = arr.size();
        for(int i=0;i<(k==1 ? n : 2*n);i++){
            int idx = i%n;
            s = (s + arr[idx]);
            a=max(s , a);
            if(s<0){
                s=0;
            }
        }
        
        if(k==1 || k==2) return (int)a%m;
        
        int  sum=0;
        for(auto i :arr) sum = (sum + i);
        if(sum >0){
            long res = a + ((long)(k-2)*sum);
            cout<<res;
            return (int)(res%m);
            
        }else{
            return a;
        }
        
    }
};