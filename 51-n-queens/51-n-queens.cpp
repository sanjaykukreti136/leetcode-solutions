class Solution {
public:
    vector<vector<string>>ans;
    bool issafe(vector<vector<char>>v , int r, int c){
    int i=r, j = c;
    while(i>=0){
        if(v[i][j]=='Q') return false;
        i--;
    }

    i=r, j=c;
    while(j>=0){
        if(v[i][j]=='Q') return false;
        j--;
    }

    i=r, j=c;
    while(i>=0 && j>=0){
        if(v[i][j]=='Q') return false;
        i--;
        j--;
    }

    i=r, j=c;
    while(i>=0 && j<v.size()){
        if(v[i][j]=='Q') return false;
        i--;
        j++;
    }
    
    return true;
    
    
}

    void check(vector<vector<char>>&v, int n , int r, int c){
    if(r == v.size()){

        if(n == 0){
            vector<string>temp;
            for(int i=0;i<v.size();i++){
                string s= "";
                for(int j=0;j<v.size();j++){
                    s+=v[i][j];
                  
                }
               
                temp.push_back(s);
            }
            ans.push_back(temp);
          
        }
        return;
    }
    
     for(int j=0;j<v.size();j++){
            if( issafe(v , r , j) ){
                v[r][j] = 'Q';
                check(v , n-1 , r+1 , 0 );
                v[r][j]='.';
            }
        }
    
    
    
}

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<char>>v(n, vector<char>(n, '.'));
        check(v, n, 0 , 0);
        return ans;
    }
};