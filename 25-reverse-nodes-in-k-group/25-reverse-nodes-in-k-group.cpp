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
    int find_size(ListNode *t){
        ListNode *temp = t;
        int c=0;
        while(temp){
            c++;
            temp = temp->next;
        }
        return c;
    }
    ListNode *th = NULL;
    ListNode *tt = NULL;
    void add(ListNode *t){
        if(th == NULL){
            th = tt = t;
        }else{
            t->next = th ; 
            th = t;
        }
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        int size = find_size(head);
        ListNode *oh = NULL;
        ListNode *ot = NULL;
        while(size >= k){
            int v = k;
            while(v--){
                ListNode *t = head->next;
                head->next = NULL;
                add(head);
                head = t;
            }
            if(oh == NULL){
                oh = th;
                ot = tt;
            }else{
                ot->next = th;
                ot = tt;
            }
            th = NULL;
            tt = NULL;
            size-=k;
        }
        ot->next  = head;
        return oh ;
    }
};