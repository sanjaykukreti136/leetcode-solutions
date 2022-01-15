class Solution {
public:
    int minJumps(vector<int>& arr) {
        map<int,vector<int>>m;
        int idx = 0;
        
        if(arr.size()==0 || arr.size()==1) return 0;
        
        for(auto i : arr){
           
            m[i].push_back(idx++);
        }
        
        queue<int>q;
        q.push(0);
        int s= 0;
        while(!q.empty()){
            s++;
            int size = q.size();
            for(int i=0;i<size;i++){
                
                int j = q.front();
                q.pop();
                
                if(j-1 >=0 && m.find(arr[j-1])!=m.end() ){
                    q.push(j-1);
                }
                
                if(j+1 < arr.size() && m.find(arr[j+1])!=m.end() ){
                    if(j+1 == arr.size()-1)  return s;
                    q.push(j+1);
                }
                
                if(m.find(arr[j])!=m.end()){
                    for(auto k : m[arr[j]]){
                        if(k!=j){
                            if(k==arr.size()-1)  return s;
                            q.push(k);
                         }
                    }
                }
                
                m.erase(arr[j]);
                
            }
        }
        return s;
        
    }
};