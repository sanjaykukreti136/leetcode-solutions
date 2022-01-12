class Solution {
public:
  bool issafe(vector<vector<char>>&board, int val, int x, int y){
        for(int i=0;i<9;i++){
            if(board[x][i]==val+'0'){
                return false;
            }
        }
        for(int i=0;i<9;i++){
            if(board[i][y]==val+'0'){
                return false;
            }
        }
        
        for(int i = 3*(x/3); i<=3*(x/3)+2; i++){
            for(int j = 3*(y/3);j<=3*(y/3)+2;j++){
                if(board[i][j]== val+'0'){
                    return false;
                }
            }
        }
        return true;
        
    }
 bool check(vector<vector<char>>&v, int i, int j){
    if(i==9 && j==0) return true;
   
    if(v[i][j]=='.'){
    for(int k=1;k<=9;k++){
        if(issafe(v, k,i ,j   )){
            int nrow, ncol;
            if(j>=8){
                nrow = i+1;
                ncol =0;
            }else{
                nrow = i;
                ncol = j+1;
            }
            v[i][j]= k+'0';
            // check
            if(i==8 && j==8) return true;
            if(check(v, nrow, ncol)) return true;
            v[i][j] = '.';
        }
    }
    }
     else{
         int nrow, ncol;
            if(j>=8){
                nrow = i+1;
                ncol =0;
            }else{
                nrow = i;
                ncol = j+1;
            }
        if(check(v, nrow, ncol)) return true;
         
     }
    return false;
    
}
    void solveSudoku(vector<vector<char>>& board) {
        check(board, 0, 0);
    }
};