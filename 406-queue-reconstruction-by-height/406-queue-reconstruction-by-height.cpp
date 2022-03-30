class Solution {
public:
    
   static bool sortbysec(const pair<int,int> &a,
              const pair<int,int> &b)
{
    if(a.first == b.first)
        return (a.second < b.second);
    return a.first < b.first;
}
  
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<pair<int,int>>v;
        for(auto i : people){
            v.push_back({ i[0] , i[1] });
        }
        
        sort(v.begin() , v.end() , sortbysec);
        for(auto i : v){
            cout<<i.first<<" "<<i.second<<"\n";
        }
        
        int n = people.size();
        vector<vector<int>>ans(n , vector<int>(2, -1));
        
        for(int i=0;i<n;i++){
            int count = v[i].second;
            for(int j=0;j<n;j++){
                if(count == 0 && ans[j][0]==-1 ){
                    ans[j][0] = v[i].first;
                    ans[j][1] = v[i].second;
                    break;
                }else if(ans[j][0]>= v[i].first  || ans[j][0]==-1 ){
                    count--;
                }
            }
        }
        return ans;
        
        
        // return ans;
    }
};