class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int ans = INT_MAX ;
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        
        int n = heights.size(),  m= heights[0].size();
        vector<vector<int>>dp(n ,vector<int>(m, INT_MAX));
        
        pq.push({ 0 , 0  , 0 , 0  });
        
        while(!pq.empty()){
            vector<int>t = pq.top();
            pq.pop();
            int dis = t[0];
            int v = t[1];
            int sr = t[2];
            int sc = t[3];
            if(sr==n-1 && sc == m-1) {
                return dis;
            }
            if(dis >= dp[sr][sc]) continue;
            dp[sr][sc] = dis; 
            
            if(sr-1>=0  ){
                // dp[sr-1][sc]=0;
                pq.push({ max(dis , abs(heights[sr][sc]-heights[sr-1][sc]) ) , heights[sr-1][sc], sr-1,sc });
            }
            if(sr+1<n  ){
                // dp[sr+1][sc]=0;
                pq.push({ max(dis , abs(heights[sr][sc]-heights[sr+1][sc]) ) , heights[sr+1][sc], sr+1,sc });
            }
            if(sc-1>=0  ){
                // dp[sr][sc-1]=0;
                pq.push({ max(dis , abs(heights[sr][sc]-heights[sr][sc-1]) ) , heights[sr][sc-1], sr,sc-1 });
            }
            if(sc+1<m  ){
                // dp[sr][sc+1]=0;
                pq.push({ max(dis , abs(heights[sr][sc]-heights[sr][sc+1]) ) , heights[sr][sc+1], sr,sc+1 });
            }
            
        }
        return ans==INT_MAX? -1 : ans;
        
    }
};