

class LRUCache {
public:
class node {
        public:
            int key;
            int val;
            node* next;
            node* prev;
        node(int _key, int _val) {
            key = _key;
            val = _val; 
        }
    };
    
    node* head = NULL;
    node* tail = NULL;
    
    int cap;
    int size= 0;
    unordered_map<int, node*>m;
    
    void addlast(node *temp){
        
        if(size==0){
            head= tail =  temp;
            size++;
            return ;
        }
        else{

        tail->next  = temp;
        temp->prev  = tail;
        tail = temp;
            size++;
        }
        
    }
    
    void removelast(){
        if(size==0) return ;
        else{
            node *t = tail->prev;
            t->next = NULL;
            tail = t;
            size--;
        }
    }
    
    void remove(node *t){
        if(size== 0){
            return ;
        }
       else if(t==head){
            removefirst();
        }
        else if(t==tail){
            removelast();
        }
        else{
           node *a  = t->next;
           node *b  = t->prev;
           b->next = a;
            a->prev = b;
            size--;
        }

    }
    
    void removefirst(){
        if(size ==0 ) return ;
        else if(size==1){
            head= tail  = NULL;
        }
        else{
            node *hn = head->next;
            head->next = NULL;
            hn->prev = NULL;
            head = hn;
        }
        size--;
    }
    
    
    
    LRUCache(int capacity) {
        cap = capacity;
      
    }
    
    int get(int key) {
         if(m.find(key)!=m.end()){
              
             int ans = m[key]->val;
             node *t = m[key];
         //    m.erase(key);
             remove(t);
             addlast(t);
          //   cout<<tail->val<<"  = \n";
          //   m[key] = t;
             return ans;
             
         }
         
         return -1;
    }
    
    void put(int key, int value) {
          if(m.find(key)==m.end()){
              node *newnode = new node(key , value);
              m[key] = newnode;
              addlast(newnode);
              
              if(size > cap ){
                  int ke = head->key;
                  removefirst();
                  m.erase(ke);
              }
              
          }
        else{
            node *curr = m[key];
            remove(curr);
            addlast(curr);
            curr->val = value;
        }

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */