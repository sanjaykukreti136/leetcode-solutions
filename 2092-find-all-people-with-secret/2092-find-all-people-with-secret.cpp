
class DSU{
    public :
      vector<int>id;
    
      DSU(int n) : id(n){
          iota(begin(id), end(id) , 0);
      }
      void connect(int a, int b){
          id[find(a)]= find(b);
      }
    
      int find(int a){
          return id[a]==a ? a : id[a] = find(id[a]);
      }
      
      bool isConnect(int a , int b){
          return id[find(a)]==id[find(b)];
      }
    
      void reset(int n){
          id[n] = n;
      }
};

class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& v, int fp) {
        DSU d(n);
        sort(v.begin(), v.end() , [](auto &a, auto &b){ return a[2] < b[2] ;});
        vector<int>ans;
        vector<int>temp;
        d.connect(0 , fp);
        int M = v.size();
        for(int i=0;i<M;){
            temp.clear();
            int time = v[i][2];
            
            for( ;i<M && v[i][2]==time ; ++i){
                if(v[i][2]==time){
                    int x = v[i][0];
                    int y = v[i][1];
                    d.connect(x, y);
                    temp.push_back(x);
                    temp.push_back(y);
                }
            }
            for(auto i : temp){
                if(d.isConnect(0 , i)==false) d.reset(i);
            }
            
        }
        
        for(int i=0;i<n;i++){
            if(d.isConnect(0 , i)) ans.push_back(i);
        }
        return ans;
    }
};