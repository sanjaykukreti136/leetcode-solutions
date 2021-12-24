class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        stack<int>s;
        s.push(intervals[0][0]);
        s.push(intervals[0][1]);
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0] > s.top()){
                s.push(intervals[i][0]);
                s.push(intervals[i][1]);
            }
            else if(intervals[i][1] > s.top()){
                s.pop();
                s.push(intervals[i][1]);
            }
        }
        vector<vector<int>>ans;
        while(!s.empty()){
            vector<int>temp;
            int a= s.top();
            s.pop();
            int b = s.top();
            s.pop();
            temp.push_back(b);
            temp.push_back(a);
            ans.push_back(temp);
        }
         reverse(ans.begin(), ans.end());
        return ans;
        
    }
};