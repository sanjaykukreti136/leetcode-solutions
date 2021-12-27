class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[i].size();j++){
                if(i==0 && j==0){
                    continue;
                }
                if(i!=0 &&  j!=0){
                    mat[i][j]+= mat[i-1][j] + mat[i][j-1] - mat[i-1][j-1];
                }else if(i==0){
                    mat[i][j]+= mat[i][j-1];
                }else{
                    mat[i][j]+= mat[i-1][j];
                }
            }
        }
        
        int m = mat[0].size();
        int n = mat.size();
        vector<vector<int>>ans;
        vector<int>t(m , 0 );
        for(int i=0;i<n;i++){
            ans.push_back(t);
        }
        for(int i=0;i<mat.size();i++){
            
            for(int j=0;j<mat[0].size();j++){
                int minr = i-k;
                int minc = j-k;
                int maxr = i+k >=mat.size() ? mat.size()-1 : i+k ;
                int maxc = j+k >=mat[i].size() ? mat[i].size()-1 : j+k ;
                
                int val = mat[maxr][maxc];
                if( minr >0 && minc >0 ){
                    minr = minr-1;
                    minc= minc-1;
                    val+= mat[minr][minc];
                    val-= mat[maxr][minc];
                    val-=mat[minr][maxc];
                }else if(minr > 0){
                    val-= mat[minr-1][maxc];
                }else if(minc > 0){
                    val-=mat[maxr][minc-1];
                }
                ans[i][j] = val;

            }
        }
        return ans;

        
    }
};