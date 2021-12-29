class Solution {
public:
    int numTrees(int n) {
        if(n==0) return 1;
        else if(n==1 || n==2) return n;
        int a[n+1];
        a[0]=1;
        a[1] =1;
        a[2]=2;
        for(int i=3;i<=n;i++){
           int x = i;
           int ans = 0;
           for(int j=0;j<x;j++){
               int first = j;
               int second = x-j-1;
               ans+= a[first]*a[second];
               
           }
           a[i] = ans;
        }
        return a[n];
    }
};