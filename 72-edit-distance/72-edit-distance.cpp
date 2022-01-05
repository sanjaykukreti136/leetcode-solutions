class Solution {
public:
    int minDistance(string s1, string s2) {
        s1 = "." + s1;
        s2 = "." + s2;
        int n = s1.length();
        int m =  s2.length();
        int a[n][m];
        for(int i = 0;i<n;i++){
            for(int j =0;j<m;j++){
                if(i==0 && j==0){
                    a[i][j] =0;
                }else if(i==0){
                    a[i][j] = j;
                }
                else if(j==0){
                    a[i][j] = i;
                }
                else{
                    
                    if(s1[i] == s2[j]){
                        a[i][j] = a[i-1][j-1];
                    }
                    else {
                        int val = min(min(a[i][j-1] , a[i-1][j]), a[i-1][j-1]);
                        a[i][j] = val+1;
                    }
                    
                }
            }
        }
        return a[n-1][m-1];
    }
};