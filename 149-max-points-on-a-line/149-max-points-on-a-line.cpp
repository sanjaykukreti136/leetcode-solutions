class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
       if(points.size()<=2) return points.size();
        int res = 0;
        for(int i=0;i<points.size();i++){
            for(int j=i+1;j<points.size();j++){
                 int t= 2;
                for(int k=j+1;k<points.size();k++){
                    if((points[j][1]-points[i][1])*(points[k][0]-points[j][0]) == (points[k][1]-points[j][1])*(points[j][0]-points[i][0]) ) t++;
                }
                res = max(res , t);
            }
        }
        return res;
    }
};