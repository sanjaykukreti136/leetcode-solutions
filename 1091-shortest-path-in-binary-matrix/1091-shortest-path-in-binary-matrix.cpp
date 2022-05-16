class Solution {
public:
    int dr[8] = {1,1,0,1,-1,-1,0,-1};
    int dc[8] = {1,0,1,-1,1,0,-1,-1};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
       queue<pair<int,pair<int,int>>>q;
       int n = grid.size() , m = grid[0].size();
        if(grid[0][0] || grid[n-1][m-1]) return -1;
        q.push({ 1  , { 0 , 0} });
        grid[0][0]=1;
        while(!q.empty()){
            int s = q.size();
            // d++;
            for(int i=0;i<s;i++){
                int d = q.front().first;
                int xx = q.front().second.first;
                int yy = q.front().second.second;
                q.pop();
                if(xx == n-1 && yy==m-1) return d;
                for(int i=0;i<8;i++){
                    
                    int x = xx+dr[i];
                    int y = yy+dc[i];
                    if(x < 0 || x>=n || y<0 || y>=m || grid[x][y]==1) continue;
                    grid[x][y] = 1;
                    q.push({d+1 , {x,y}});
                    
                }
                
            }
        }
        return -1;
    }
};