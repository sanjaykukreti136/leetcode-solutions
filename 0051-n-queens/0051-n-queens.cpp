class Solution {
public:
    

void check(vector<vector<char>>&v,int n, int row,vector<int>colo,vector<int>di1,vector<int>di2,vector<vector<string>>&ans){
    if(row==n){
        vector<string>tt;
        for(int i=0;i<n;i++){
            string s="";
            for(int j=0;j<n;j++){
                (v[i][j]=='-') ? s+='.' : s+='Q';
            }
            tt.push_back(s);
        }
        if(tt.size()>0) ans.push_back(tt);
        cout<<".\n";
       return ;
    }
    for(int i =0;i<n;i++){
        if( colo[i]==0 && di1[row+i]==0 && di2[row-i+(n-1)]==0 ){
            di2[row-i+(n-1)] = 1;
            di1[row+i] = 1;
            colo[i] = 1;
            v[row][i] = 'q';
            check(v, n,  row+1, colo,di1,di2,ans);
            v[row][i] = '-';
            colo[i]= 0;
            di1[row+i] = 0;
            di2[row-i+(n-1)] = 0;
        }
    }
    
    
}

    vector<vector<string>> solveNQueens(int n) {
    vector<vector<char>>v(n , vector<char>(n, '-'));
    vector<int>colo(n, 0);
    vector<int>di1(2*n-1, 0);
    vector<int>di2(2*n-1,0);
    vector<vector<string>>ans;
    check(v , n, 0 , colo,di1,di2, ans);
        return ans;
    }
};