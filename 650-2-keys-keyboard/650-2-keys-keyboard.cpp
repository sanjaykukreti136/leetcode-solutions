class Solution {
public:
    
    int check(int n , int curr , int copy){
        if(curr == n) return 0;
        if(curr > n) return 1e9;
        
        return min(check(n , curr+copy , curr+copy)+2 , check(n , curr+copy , copy)+1 );
// return min( min( check(n , curr*2, curr*2), check(n , curr*2 , curr) ) , check(n , copy+curr , curr) )+1;
        // if(2*curr <= n)
        // return min(curr ,  )
        
    }
    
    int minSteps(int n) {
        if(n == 1) return 0;
       return  check(n , 1 , 1)+1;
    }
};