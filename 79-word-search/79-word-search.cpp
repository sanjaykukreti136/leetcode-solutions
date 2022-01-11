class Solution {
public:
    
    bool check(vector<vector<char>>&board, int i, int j, string s , int idx){
        if(idx == s.length()) return true;
        if(i<0 || i>=board.size() || j<0 || j>=board[0].size() || board[i][j]=='.' || board[i][j]!=s[idx] ) return false;
        char ch = board[i][j];
        board[i][j]= '.';
        
        bool ans = false;
        ans = ans || check(board, i-1, j, s, idx+1)|| check(board, i+1, j, s, idx+1)|| check(board, i, j-1, s, idx+1)|| check(board, i, j+1, s, idx+1) ; 
        board[i][j] = ch;
        return ans;
        
    }
    
    bool exist(vector<vector<char>>& board, string s) {
        
        int n = board.size();
        int m = board[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==s[0]){
                   if( check(board , i , j , s , 0 )) return true;
                }
            }
        }
        return false;
    }
};