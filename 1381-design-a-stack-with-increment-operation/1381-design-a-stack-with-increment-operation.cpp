class CustomStack {
public:
    int *arr;
    int idx;
    int n ;
    CustomStack(int maxSize) {
        idx = 0;
        n = maxSize;
        arr = new int[maxSize];
    }
    
    void push(int x) {
        if(idx < n){
            arr[idx] = x;
            idx++;
        }
    }
    
    int pop() {
        if(idx == 0) return -1;
        int val = arr[idx-1];
        idx-=1;
        return val;
    }
    
    void increment(int k, int val) {
        for(int i=0;i<min(k,idx);i++){
            arr[i]+=val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */