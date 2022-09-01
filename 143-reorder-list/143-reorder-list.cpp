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
    
    ListNode *findMid(ListNode *head){
        ListNode *s = head;
        ListNode *f = head;
        while(f && f->next){
            f = f->next->next;
            s = s->next;
        }
        ListNode *t = s->next;
        s->next = NULL;
        return t;
    }
    ListNode *reverse(ListNode *head){
        ListNode *pre = NULL;
        while(head){
            ListNode *temp = head->next;
            head->next = pre;
            pre = head;
            head = temp;
        }
        return pre;
    }
    
    void reorderList(ListNode* head) {
        ListNode *mid = findMid(head);
        
        ListNode *start = head ; 
        ListNode *second = reverse(mid);
        
        while(start && second){
            ListNode *temp = start->next;
            ListNode *temp1 = second->next;
            second->next = temp;
            start->next = second;
            start = temp;
            second = temp1;
        }
        
    }
};