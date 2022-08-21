class MedianFinder {
public:
    
    priority_queue<int,vector<int>,greater<int>>right;
    priority_queue<int>left;
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(left.size()==0){
            left.push(num);
        }else if(left.size()==right.size()){
            
            if(num > right.top()){
                int t = right.top();
                right.pop();
                left.push(t);
                right.push(num);
            }else{
                left.push(num);
            }
            
        }else{
            
            if(right.size()==0){
                if(num >= left.top()){
                    right.push(num);
                }else{
                    int t = left.top();
                    left.pop();
                    left.push(num);
                    right.push(t);
                }
            }else{
                
                if(num >= left.top()){
                    right.push(num);
                }else{
                    int t = left.top();
                    left.pop();
                    left.push(num);
                    right.push(t);
                }
                
            }
            
        }
    }
    
    double findMedian() {
        if(left.size()==right.size()){
            return (double)(left.top() + right.top())/2.0;
        }else{
            return (double)(left.top());
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */