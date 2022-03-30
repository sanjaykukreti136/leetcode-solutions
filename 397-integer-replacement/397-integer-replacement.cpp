class Solution {
public:
    
    unordered_map<int,int>m;
    
    int check(int n){
        if(n==1) return 0;
        
        if(m.find(n)!=m.end()) return m[n];
        int ans = n-1;
        if(n%2==0){
            ans = min(ans ,  check(n/2)  +1 );
        }else{
            ans = min(ans , min( check(n-1) , check(n+1) ) + 1);
        }
        return m[n] = ans;
    }
    
    int integerReplacement(int n) {
        // return 0;
        m[INT_MAX]  = 32;
        return check(n);
    }
};