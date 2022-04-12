class MedianFinder {
public:
     priority_queue<int> left; //1st half (left half)
    priority_queue<int,vector<int>,greater<int>> right;
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        
        if(left.size()==0){
            left.push(num);
        }
        else if(left.size()== right.size()){
            
            if(num<=right.top()){
                left.push(num);
            }
            else{
                
                int t= right.top();
                right.pop();
                left.push(t);
                right.push(num);
                
            }
            
        }
        else{
            if(right.size()==0){
                if(num >= left.top()){
                    right.push(num);
                }
                else{
                int t= left.top();
                left.pop();
                left.push(num);
                right.push(t);
                
                }
            }
            else if( num >= right.top() ){
                right.push(num);
            }
            else{
                if( num <left.top() ){
                int t= left.top();
                left.pop();
                left.push(num);
                right.push(t);
                }
                else{
                    right.push(num);
                }
            }
            
            
            
        }
        
    }
    
    double findMedian() {
        int lsize = left.size();
        int rsize = right.size();
        cout<<lsize<<" - "<<rsize<<"\n";
        if(lsize > rsize)  //Return top of maxheap for odd no of elements
            return double(left.top());
        else    //Else return avg of top of maxheap and minheap
            return (double(left.top())+double(right.top()))/2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */