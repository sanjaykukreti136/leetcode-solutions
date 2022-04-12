class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
       int n = board.size();
        int m = board[0].size();
        for(int i =0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
             
                int c =1;
                if((i-1)>=0 && (j-1)>=0){
                    if(board[i-1][j-1] >0) c++;
                }
                
                if((i-1)>=0){
                    if(board[i-1][j] >0) c++;
                }
                
                if((i-1)>=0 && (j+1)<board[0].size()){
                    if(board[i-1][j+1] >0) c++;
                }
                
                if((j-1)>=0){
                    if(board[i][j-1] >0) c++;
                }
                
                if((j+1)<board[0].size()){
                    if(board[i][j+1] >0) c++;
                }
                
                if((i+1)<board.size() && (j-1)>=0){
                    if(board[i+1][j-1] >0) c++;
                }
                
                if((i+1)<board.size()){
                    if(board[i+1][j] >0) c++;
                }
                
                if((i+1)<board.size() && (j+1)<board[0].size()){
                    if(board[i+1][j+1] >0) c++;
                }
                
                if(board[i][j]==0){
                    board[i][j] = -c;
                }else{
                    board[i][j] = c;
                } 
            }
        }
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]<0){
                    if(board[i][j]==-4){
                        board[i][j] = 1;
                    }else{
                        board[i][j]=0;
                    }
                }
                else{
                    if(board[i][j]==3 || board[i][j] ==4){
                        board[i][j] = 1;
                    }else{
                        board[i][j] = 0;
                    }
                }
            }
        }
    }
};