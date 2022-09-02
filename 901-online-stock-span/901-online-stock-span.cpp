class StockSpanner {
public:
    stack<pair<int,int>>s;
    int idx ;
    StockSpanner() {
        idx = -1;
    }
    
    int next(int price) {
        idx++;
        while(!s.empty() && s.top().second <= price ){
            s.pop();
        }
        int ans = 0;
        if(s.empty()){
            ans = idx+1;
            // return idx+1;
        }
        else{
            ans =  idx - s.top().first;
        }
        
        s.push({ idx , price });
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */