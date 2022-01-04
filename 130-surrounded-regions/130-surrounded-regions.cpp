// class Solution {
// public:
//     void check(vector<vector<char>>&graph , int i , int j){
//         if(i<0 || j<0 || i>=graph.size() || j>=graph[i].size() || graph[i][j]!='O') return ;
//         graph[i][j] = '#';
//         check(graph  , i-1,j);
//         check(graph  , i+1,j);
//         check(graph  , i,j-1);
//         check(graph  , i,j+1);
//     }
//     void solve(vector<vector<char>>& graph) {
//         for(int i=0;i<graph.size();i++){
//             for(int j=0;j<graph[i].size();j++){
//                 if(i==0 || j==0 || i==graph.size()-1 || j==graph[i].size()-1 && graph[i][j]=='O'){
//                     check(graph, i  , j);
//                 }
//             }
//         }
        
//         for(int i=0;i<graph.size();i++){
//             for(int j=0;j<graph[i].size();j++){
//                 if(graph[i][j]=='#'){
//                     graph[i][j]='O';
//                 }else{
//                     graph[i][j]='X';
//                 }
//             }
//         }
//     }
// };


class Solution {
public:
    void dfs(int sr,int sc,vector<vector<int>>&dir, vector<vector<char>>&board)
    {
        board[sr][sc]='#';
        for(auto d:dir)
        {
            int r=sr+d[0];
            int c=sc+d[1];
            if(r>=0 and c>=0 and r<board.size() and c<board[0].size() and board[r][c]=='O')
                dfs(r,c,dir,board);
        }
    }
    void solve(vector<vector<char>>& board) {
        if(board.size()==0) return;
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>>dir{{0,1},{1,0},{0,-1},{-1,0}};
        // traverse through borders 
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(i==0 or i==n-1 or j==0 or j==m-1)
                {
                   if(board[i][j]=='O')
                       dfs(i,j,dir,board);
                }
            }
        }
        // now traverse the board to flip all non connected border zeroes into 'X'
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j]=='#')
                    board[i][j]='O';
                else if(board[i][j]=='O')
                    board[i][j]='X';
            }
        }
        return;
    }
};