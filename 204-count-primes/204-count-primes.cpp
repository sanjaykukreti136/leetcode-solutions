class Solution {
public:
    int countPrimes(int n) {
        vector<bool>a(n+1 , true);
        for(int i=2;i*i<=n;i++){
            if(a[i]==true){
            for(int j=2*i;j<=n;j+=i){
                
                a[j] = false;
            }
            }
        }
        
        int c=0;
        for(int i=2;i<n;i++){
            if(a[i]) c++;
        }
        return c;
        
    }
};