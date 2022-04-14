class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>>v;
        priority_queue<int>pq;
        int prof = w;
        for(int i=0;i<profits.size();i++){
            v.push_back({ capital[i] , profits[i] });
        }
        sort(v.begin(), v.end());
        
        int idx = 0;
        for(idx =0 ;idx < v.size();idx++){
            
            if(v[idx].first <= w){
                
                pq.push(v[idx].second);
            }else{
                break;
            }
            
        }
        
        while(k--){
            
            if(pq.empty()) break;
            
            prof+=pq.top();
            pq.pop();
            for(;idx<v.size();idx++){
                if(v[idx].first <= prof){
                    pq.push(v[idx].second);
                }else{
                    break;
                }
            }
            
        }
        return prof;
        
    }
};