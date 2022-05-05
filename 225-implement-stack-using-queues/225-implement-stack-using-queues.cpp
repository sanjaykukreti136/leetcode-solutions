class MyStack {
public:
    queue<int> q;
   
    void push(int x) {
        queue<int> temp;
        while(!q.empty()) {
            temp.push(q.front());
            q.pop();
        }
        
        q.push(x);
        
         while(!temp.empty()) {
            q.push(temp.front());
            temp.pop();
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