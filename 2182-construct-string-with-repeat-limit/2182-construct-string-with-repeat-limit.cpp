class Solution {
public:
    string repeatLimitedString(string s, int k) {
  string ans = "";
    
    unordered_map<char , int>mp;
    
    for(int i = 0 ; i < s.size() ; i++){
        mp[s[i]]++;
    }
    
    priority_queue<pair<char , int>>pq;
    
    for(auto value : mp){
        pq.push({value.first ,  value.second});
    }
    
    while(!pq.empty()){
        char first = pq.top().first;
        int second = pq.top().second;
        pq.pop();
        
        int size = min(second , k);
        
        for(int i = 0 ; i < size ; i++){
            ans += first;
        }
        
        if(second - k > 0){
            if(!pq.empty()){
                char first2 = pq.top().first;
                int second2 = pq.top().second;
                pq.pop();
                ans += first2;
                if(second2 - 1 > 0){
                    pq.push({first2 , second2 - 1});
                }
            }else{
                return ans;
            }
            pq.push({first , second - k});
        }
    }
    
    return ans;
}
};