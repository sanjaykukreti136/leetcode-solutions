class MinStack {
public:
    int idx = -1;
    vector<int>stac;
    vector<int>mi;
    MinStack() {
        
    }
    
    void push(int val) {
        
        if(idx==-1){
            stac.push_back(val);
            mi.push_back(val);
        }else{
            stac.push_back(val);
            mi.push_back(min(mi[mi.size()-1] , val));
        }
        idx++;
        
    }
    
    void pop() {
        if(idx==-1) return ;
        idx--;
        int val= stac[stac.size()-1];
        stac.pop_back();
        mi.pop_back();
        // return val;
        
        
    }
    
    int top() {
        if(idx==-1) return -1;
        return stac[idx];
    }
    
    int getMin() {
        if(idx==-1) return -1;
        return mi[idx];
    }
};
