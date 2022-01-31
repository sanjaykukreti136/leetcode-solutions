class Solution {
public:
    
    bool check(vector<vector<int>>&v, int r, int c){
        int a[9] = {0};
        cout<<r<<" - "<<c<<"\n";
        for(int i=r;i<r+3;i++){
            for(int j=c;j<c+3;j++){
                if(v[i][j]>9 || v[i][j]<=0 || a[v[i][j]-1]!=0 ) return false;
                a[v[i][j]-1] = 1;
            }
        }
        cout<<"a\n";
        //
        for(int i=r;i<r+3;i++){
            int s=0;
            for(int j=c;j<3+c;j++){
                s+=v[i][j];
            }
            if(s!=15) return false;
        }
        cout<<"a\n";
        for(int i=c;i<c+3;i++){
            int s=0;
            for(int j=r;j<3+r;j++){
                s+=v[j][i];
            }
            if(s!=15) return false;
        }
        cout<<"a\n";
        int first_diag = v[r][c] + v[r+1][c+1] + v[r+2][c+2];
        if(first_diag!=15) return false;
        cout<<"a\n";
        int second = v[r][c+2] + v[r+1][c+1] + v[r+2][c];
        if(second!=15) return false;
        return true;
        
    }
    
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int c=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(i+2 < grid.size() && j+2<grid[j].size() && grid[i+1][j+1]==5 ){
                    if(check(grid , i, j)) c++;
                }
            }
        }
        return c;
    }
};