class Solution {
public:
    bool isRobotBounded(string s) {
        vector<vector<int>>d = { { 0 , 1 } , { -1 , 0 } , { 0 ,-1 } , { 1 , 0 } };
        
        int dir = 0;
        int x=0,y=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='L'){
                dir = (dir+1)%4;
            }else if(s[i]=='R'){
                dir = (dir+3)%4;
            }else{
                x += d[dir][0];
                y += d[dir][1];
            }
        }
        return (x==0 && y==0) || dir!=0;
    }
};