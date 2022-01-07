
class Solution {
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    vector<int>v;
    Solution(ListNode* head) {
        ListNode *t= head;
        while(t){
            v.push_back(t->val);
            t = t->next;
        }
    }
    
    /** Returns a random node's value. */
    int getRandom() {
      return   v[rand() % v.size()]; 
    }
};

