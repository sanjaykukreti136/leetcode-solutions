/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode *oh = NULL;
        ListNode *eh = NULL;
        ListNode *o = NULL;
        ListNode *e = NULL;
        ListNode *temp  = head;
        int c = 1;
        while(temp){
            if(c%2==0){
                if(eh == NULL){
                    eh = e = temp;
                }else{
                    e->next = temp;
                    e = e->next;
                }
            }
            else{
                if(oh == NULL){
                    oh = o = temp;
                }else{
                    o->next = temp;
                    o = o->next;
                }
            }
            temp = temp->next;
            c++;
        }
        
        if(oh == NULL && eh == NULL){
             return NULL;
        }
        else if( oh  == NULL){
            e->next =NULL;
            return eh;
        }
        else if(eh == NULL){
          o->next = eh;
          return oh;
        }
        e->next =NULL;
        o->next = eh;
        return oh;


    }
};