class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<float,int> , vector<pair<float,int>> , greater<pair<float,int>>>pq;
        int i=0;
        for(auto v : points ){
            pq.push({ float(sqrt( (v[0]*v[0]) + (v[1]*v[1]) )) , i});
            cout<<sqrt( (v[0]*v[0]) + (v[1]*v[1]) )<<" - "<<i;
            i++;
        }
        
        vector<vector<int>>ans;
        while(k--){
            pair<float,int>p = pq.top();
            pq.pop();
            ans.push_back(points[p.second]);
        }
        return ans;
        
    }
};