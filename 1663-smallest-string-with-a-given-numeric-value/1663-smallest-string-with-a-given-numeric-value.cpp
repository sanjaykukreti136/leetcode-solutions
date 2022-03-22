class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans = "";
        
        int i=0;
        int m = n;
        for(int i=1;i<=m;i++){
            
            n-=i;
            if(k>=n && k<=n*26 ){
                ans+='a';
                k-=1;
            }
            else{
                int idx = k-(n*26);
                ans+= ('a' + (idx-1));
                k-=idx;
            }
            n =m;
            
        }
        return ans;
        
    }
};