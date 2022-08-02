class Solution {
public:
    
    bool isvalid(int r, int c , vector<vector<bool>>&vis  ,vector<vector<int>>&v){
        if(r>=v.size() || r<0 || c<0 || c>=v[0].size() || vis[r][c]==true || v[r][c]==0) return false;
        vis[r][c] = true;
        return true;
    }
    
    int check(int sr , int sc, int dr, int dc, vector<vector<int>>&v){
        int n = v.size(),  m= v[0].size();
        vector<vector<bool>>vis(n , vector<bool>(m , false));
        
        queue<pair<int,int>>q;
        q.push({sr,sc});
        vis[sr][sc] = true;
        int d = 0;
        while(!q.empty()){
            int x = q.size();
            while(x--){
                pair<int,int>p = q.front();
                q.pop();
                int cr = p.first;
                int cc = p.second;
                if(cr == dr && cc==dc) return d;
                if(isvalid(cr-1,cc , vis , v)) q.push({cr-1 , cc});
                if(isvalid(cr+1, cc , vis, v)) q.push({cr+1, cc});
                if(isvalid(cr , cc+1, vis , v)) q.push({cr , cc+1});
                if(isvalid(cr , cc-1, vis , v)) q.push({cr , cc-1});
                
            }
            d++;
        }
        return -1;
        
        
    }
    
    int cutOffTree(vector<vector<int>>& forest) {
   
       priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>>pq;
       int n = forest.size(),  m=forest[0].size();
       for(int i=0;i<n;i++){
           for(int j=0;j<m;j++){
               if(forest[i][j]>1){
                   pq.push({ forest[i][j], {i,j} });
               }
           }
       }
       int c = 0;
       int dr,dc;
       int sr=0,sc=0;
       while(!pq.empty()){
           pair<int,pair<int,int>>p = pq.top();
           pq.pop();
           dr= p.second.first;
           dc= p.second.second;
           int height = p.first;
           
           int ans = check(sr,sc,dr,dc,forest);
           if(ans == -1) return -1;
           c+=ans;
           sr = dr;
           sc = dc;
           
       }
       
       return c;
    
    }
};
