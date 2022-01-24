class Solution {
public:
    
    int check(int n, int k){
        if(n==1) return 0;
        int x = check(n-1 , k);
        int y = (x+k)%n;
        return y;
    }
    
    int findTheWinner(int n, int k) {
        return check(n , k )+1;
    }
};