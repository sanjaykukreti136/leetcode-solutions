class MyStack {
public:
    queue<int> q;
   
    void push(int x) {
        int temp =q.size();
        q.push(x);
        for(int i=0;i<temp;i++){
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        if(q.empty()) return -1;
        
        int t = q.front();
        q.pop();
        
        return t;
    }
    
    int top() {
        if(q.empty()) return -1;
        return q.front();
    }
    
    bool empty() {
        if(q.size() > 0) return false;
        else return true;
    }
};