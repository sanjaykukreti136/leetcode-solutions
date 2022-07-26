class Solution {
public:
vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    queue<pair<int,int>> q;
    for(int i=0;i<mat.size();++i){
        for(int j=0;j<mat[0].size();++j){
            if(mat[i][j] == 0)
                q.push({i,j});
            else mat[i][j]=-1;
        }
    }
    int val=1;
    while(!q.empty()){
        int len=q.size();
        for(int i=0;i<len;++i){
            pair<int,int> p=q.front();
            if(p.first+1 < mat.size() && mat[p.first+1][p.second] == -1){
                q.push({p.first+1,p.second});
                mat[p.first+1][p.second]=val;
            }
            if(p.first-1 >= 0 && mat[p.first-1][p.second] == -1){
                q.push({p.first-1,p.second});
                mat[p.first-1][p.second]=val;
            }
             if(p.second+1 < mat[0].size() && mat[p.first][p.second+1] == -1){
                q.push({p.first,p.second+1});
                 mat[p.first][p.second+1]=val;
             }
             if(p.second-1 >= 0 && mat[p.first][p.second-1] == -1){
                q.push({p.first,p.second-1});
                 mat[p.first][p.second-1]=val;
             }
            q.pop();
        }
        val++;
    }
    return mat;
}
};