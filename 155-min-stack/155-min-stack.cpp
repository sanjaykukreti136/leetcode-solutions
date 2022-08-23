class MinStack {
public:
    vector<long long>v;
    int idx = -1;
    long long minv = INT_MIN;
    MinStack() {
        
    }
    
    void push(long long val) {
        if(val >= minv){
            v.push_back(val);
            if(idx==-1) minv = val;
        }else{
            v.push_back(2*val*1LL-minv);
            minv  = val;
        }
        idx++;
    }
    
    void pop() {
        if(v[idx] < minv){
            minv = 2*minv - v[idx];
            v.pop_back();
        }else{
            v.pop_back();
            
        }
        idx--;
    }
    
    int top() {
        if(v[idx] < minv){
            return minv;
        }else{
            return v[idx];
        }
    }
    
    int getMin() {
        return minv;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */