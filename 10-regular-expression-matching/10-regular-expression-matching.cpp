class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        s = "." + s;
        p = "." + p;
        bool a[m+1][n+1];
        for(int i =1;i<=n;i++){
            a[0][i] = false;
        }
        a[0][0]  = true;
        for(int i = 1;i<=m;i++){
            if(p[i] != '*'){
                a[i][0] = false;
            }else{
                a[i][0]= a[i-2][0];
            }
        }
        for(int i = 1;i<=m;i++){
            for(int j = 1;j<=n;j++){
                cout<<p[i]<<" - "<<s[j]<<"\n";;
                if(p[i]!='*' && p[i]!='.'){
                 //   cout<<i<<j<<"\n";
                    if(p[i] == s[j]){
                        a[i][j] = a[i-1][j-1];
                    }else{
                        a[i][j] = false;
                    }
                }
                else if(p[i] == '.'){
                   // cout<<i<<j<<"\n";
                    a[i][j] = a[i-1][j-1];
                }
                else {
                   // cout<<i<<j<<"\n";
                    if(p[i-1]==s[j] || p[i-1] == '.'){
                        a[i][j] = (a[i-2][j] || a[i][j-1]);
                    }
                    else{
                        a[i][j] = a[i-2][j];
                    }
                    
                }
                
                
            }
        }
        for(int i= 0;i<=m;i++){
            for(int j=0;j<=n;j++){
                cout<<a[i][j]<<" ";
            }
            cout<<"\n";
        }
        return a[m][n];
    }
};