class MyCircularDeque {
    struct Node{
        int data;
        Node *next;
        Node *prev;
        Node(int d){
            data = d;
        }
    };
public:
    int size = 0;
    int s = 0;
    Node *head = NULL;
    Node *tail = NULL;
    MyCircularDeque(int k) {
        size = k;
    }
    
    bool insertFront(int value) {
        if(s < size){
            Node *newnode = new Node(value);
            if(head == NULL){
                head = tail = newnode;
            }else{
                newnode->next = head;
                head->prev = newnode;
                head = newnode;
            }
            s++;
            return true;
            
        }
        return false;
    }
    
    bool insertLast(int value) {
        if(s < size){
            Node *newnode = new Node(value);
            if(head == NULL){
                head = tail = newnode;
            }else{
                newnode->prev= tail;
                tail->next = newnode;
                tail = newnode;
            }
            s++;
            return true;
            
        }
        return false;
    }
    
    bool deleteFront() {
        if(s > 0){
            if(s == 1){
                head = tail = NULL;
            }else{
                head->next->prev = NULL;
                head = head->next;
            }
            s-=1;
            return true;
        }
        return false;
    }
    
    bool deleteLast() {
        if(s > 0){
            if(s==1){
                head = tail = NULL;
            }else{
                tail->prev->next = NULL;
                tail = tail->prev;
            }
            s-=1;
            return true;
        }
        return false;
    }
    
    int getFront() {
        if(s > 0){
            return head->data;
        }
        return -1;
    }
    
    int getRear() {
        if(s>0){
            return tail->data;
        }
        return -1;
    }
    
    bool isEmpty() {
        return s<=0;
    }
    
    bool isFull() {
        return s==size;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */