class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>ans;
        int top =0;
        int bot = matrix.size()-1;
        int left =0;
        int right = matrix[0].size()-1;
        int dir = 0;
        while(top<=bot && left<=right){
            if(dir==0){
                for(int i=left;i<=right;i++){
                    ans.push_back(matrix[top][i]);
                }
                top+=1;
            }
            else if(dir==1){
                for(int i = top;i<=bot;i++){
                    ans.push_back(matrix[i][right]);
                }
                right-=1;
            }
            else if(dir==2){
                for(int i=right;i>=left;i--){
                    ans.push_back(matrix[bot][i]);
                }
                bot-=1;
            }
            else if(dir==3){
                for(int i=bot;i>=top;i--){
                    ans.push_back(matrix[i][left]);
                }
                left+=1;
            }
            dir= (dir+1)%4;
        }
        return ans;
    }
};