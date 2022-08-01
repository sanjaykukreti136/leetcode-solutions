class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int co) {
        int old = image[sr][sc];
        queue<pair<int,int>>q;
        q.push({sr , sc});
      map<pair<int, int>, int> m;
  
        m[{sr,sc}] = 1;
        while(!q.empty()){
            
            int  r = q.front().first;
            int  c = q.front().second;
            q.pop();
            image[r][c] = co;
            
            if(r-1>=0 && image[r-1][c]==old && m.find({r-1 , c})==m.end() ){
                q.push({r-1 , c});
                m[{r-1,c}]=1;
            }
            if(r+1<image.size() && image[r+1][c]==old && m.find({r+1 , c})==m.end() ){
                q.push({r+1 , c});
                m[{r+1,c}]=1;
            }
            if(c-1>=0 && image[r][c-1]==old && m.find({r , c-1})==m.end() ){
                q.push({r , c-1});
                m[{r,c-1}]=1;
            }
            if(c+1<image[0].size() && image[r][c+1]==old && m.find({r , c+1})==m.end() ){
                q.push({r , c+1});
                m[{r,c+1}]=1;
            }
            
            
        }
        return image;
        
    }
};