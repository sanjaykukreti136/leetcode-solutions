class pairp{
    public :
      int id , rat, idx;
      
      pairp(int a , int b, int c){
          id = a;
          rat = b;
          idx = c;
      }
};

class Solution {
public:
    struct CompareHeight {
    bool operator()(pairp p,pairp q)
    {
         if(p.rat == q.rat){
             return p.id < q.id;
         }
         return p.rat < q.rat;
    }
};
    vector<int> filterRestaurants(vector<vector<int>>& v, int veganFriendly, int maxPrice, int maxDistance) {
        priority_queue<pairp, vector<pairp> , CompareHeight>pq;
        for(int i=0;i<v.size();i++){
            int id = v[i][0];
            int rat = v[i][1];
            pairp *t = new pairp(id, rat , i);
            pq.push(*t);
        }
        
        vector<int>ans;
        while(!pq.empty()){
            pairp p = pq.top();
            pq.pop();
            // cout<<p.second<<"\n";
            vector<int>t = v[p.idx];
            if((t[2]==veganFriendly || veganFriendly==0  ) && t[3]<=maxPrice && t[4]<= maxDistance){
                ans.push_back(p.id);
            }
        }
        return ans;
        
    }
};