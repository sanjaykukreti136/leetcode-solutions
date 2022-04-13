class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>ans;
        int c = 1;
        int top =0;
        int bot = matrix.size()-1;
        int left =0;
        int right = matrix[0].size()-1;
        int dir = 0;
        while(top<=bot && left<=right){
            if(dir==0){
                for(int i=left;i<=right;i++){
                    // ans.push_back(matrix[top][i]);
                    matrix[top][i] = c++;
                }
                top+=1;
            }
            else if(dir==1){
                for(int i = top;i<=bot;i++){
                    // ans.push_back(matrix[i][right]);
                    matrix[i][right] = c++;
                }
                right-=1;
            }
            else if(dir==2){
                for(int i=right;i>=left;i--){
                    // ans.push_back(matrix[bot][i]);
                    matrix[bot][i] = c++;
                }
                bot-=1;
            }
            else if(dir==3){
                for(int i=bot;i>=top;i--){
                    // ans.push_back(matrix[i][left]);
                    matrix[i][left] = c++;
                }
                left+=1;
            }
            dir= (dir+1)%4;
        }
        return ans;
    }

    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>matrix(n , vector<int>(n , 0));
        spiralOrder(matrix);
        return matrix;
    }
};