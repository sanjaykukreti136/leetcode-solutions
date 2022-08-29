class Solution {
public:
    int count = 1;
    int find_par(int a , vector<int>&par){
        if(a==par[a]) return a;
        return par[a] = find_par(par[a] , par);
    }
    void do_union(int a , int b , vector<int>&par){
        a = find_par(a , par);
        b = find_par(b , par);
        if(a!=b){
            par[a] = b;
        }else{
            count++;
        }
        
    }
    
    int regionsBySlashes(vector<string>& grid) {
           int n = grid.size();
           int dot = n+1;
           vector<int>par(dot*dot , -1);
           for(int i=0;i<(dot*dot);i++){
               par[i] = i;
           }
        

        for(int i=0;i<dot;i++){
            for(int j=0;j<dot;j++){
                if(i==0 || j==0 || i==dot-1 || j==dot-1){
                    int pos = i*(dot) + j;
                    if(pos==0) continue;
                    do_union(0 , pos , par);
                }
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='/'){
                    int x = i*(dot) + j + 1;
                    int y = (i+1)*dot + j;
                    do_union(x,y, par);
                }
                else if(grid[i][j]=='\\'){
                    int x = i*(dot) + j;
                    int y = (i+1)*dot + j+1;
                    do_union(x,y,par);
                }
            }
        }
        return count;
        
    }
};