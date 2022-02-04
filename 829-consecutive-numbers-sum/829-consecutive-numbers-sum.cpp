class Solution {
public:
    int consecutiveNumbersSum(int n) {
        int val = pow(1,2) + 1;
        int k = 1;
        int n2 = 2*n;
        while(val <= n2){
            k+=1;
            val = pow(k , 2) + k;
        }
        k-=1;
        cout<<k<<"\n";
        int c=0;
        for(int i=1;i<=k;i++){
            if((n-((i*(i-1))/2))%i==0) c++;
        }
        return c;
        
        
    }
};