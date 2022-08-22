class LRUCache {
public:
    
    class node{
        public :
          int key,val;
          node *next;
          node *prev;
          node(int a,  int b){
              key = a;
              val = b;
          }
        
    };
    
    node *head = NULL;
    node *tail = NULL;
    int size = 0;
    int k;
    unordered_map<int,node*>m;
    
    void addLast(node *curr){
        if(size == 0){
            head = tail = curr;
        }else{
            curr->prev = tail;
            tail->next = curr;
            tail = curr;
        }
        size++;
    }
    
    void removeFirst(){
        if(size==0){}
        else if(size == 1){
            head = tail = NULL;
            size--;
        }else{
            node *t = head->next;
            head->next = NULL;
            t->prev = NULL;
            head = t;
            size--;
        }
    }
    
    void removeLast(){
        if(size==0){}
        else if(size==1){
            head = tail = NULL;
            size--;
        }else{
            node *curr = tail;
            tail = curr->prev;
            tail->next = NULL;
            curr->prev = NULL;
            size--;
        }
    }
    
    void remove(node *curr){
        if(curr==head){
            removeFirst();
        }
        else if(curr==tail){
            removeLast();
        }else{
            node *curr_next = curr->next;
            node *curr_prev = curr->prev;
            curr_prev->next = curr_next;
            curr_next->prev = curr_prev;
            curr->next = NULL;
            curr->prev = NULL;
            size--;
        }
    }
    
    
    LRUCache(int capacity) {
         k = capacity;
    }
    
    
    
    int get(int key) {
        
        if(m.find(key)!=m.end()){
            
            node *curr = m[key];
            if(curr==head){
                removeFirst();
                addLast(curr);
            }else if(curr==tail){
                
            }else{
                remove(curr);
                addLast(curr);
            }
            return curr->val;
        }else{
            return -1;
        }
        
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end()){
            node *curr = m[key];
            curr->val = value;
            if(curr==head){
                removeFirst();
                addLast(curr);
            }else if(curr==tail){
                
            }else{
                remove(curr);
                addLast(curr);
            }
            
        }
        else{
            if(size < k){
                node *curr = new node(key , value);
                m[key] = curr;
                addLast(curr);
            }else{
                node *curr = new node(key , value);
                m[key] = curr;
                m.erase(head->key);
                removeFirst();
                addLast(curr);
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */