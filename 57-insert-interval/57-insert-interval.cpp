class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end());
        
        vector<vector<int>>res;
        int s=INT_MIN,e=INT_MIN;
        for(int i=0;i<intervals.size();i++){
            if(intervals[i][0]>e){
                res.push_back(intervals[i]);
                e = intervals[i][1];
                s = intervals[i][0];
            }else{
                if(intervals[i][1] > e){
                    res[res.size()-1][1] = intervals[i][1];
                    e = intervals[i][1];
                }
            }
        }
        return res;
        
    }
};