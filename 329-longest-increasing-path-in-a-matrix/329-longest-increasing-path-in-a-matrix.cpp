class Solution {
public:
    int dp[202][202];
    int dfs(int sr, int sc, vector<vector<int>>&matrix, int prev)
    {
        if(sr<0 or sc<0 or sr==matrix.size() or sc==matrix[0].size() or prev>=matrix[sr][sc]) 
            return 0;
        if(dp[sr][sc]!=-1) return dp[sr][sc];
        
        int a=dfs(sr,sc+1,matrix,matrix[sr][sc]);
        int b=dfs(sr,sc-1,matrix,matrix[sr][sc]);
        int c=dfs(sr+1,sc,matrix,matrix[sr][sc]);
        int d=dfs(sr-1,sc,matrix,matrix[sr][sc]);
        
        return dp[sr][sc]=max({a,b,c,d})+1;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n=matrix.size(), m=matrix[0].size();
        memset(dp,-1,sizeof(dp));
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cnt=max(cnt,dfs(i,j,matrix,-1));
            }
        }
        return cnt;
    }
};