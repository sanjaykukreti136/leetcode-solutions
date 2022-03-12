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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode *head = new ListNode(-1);
        ListNode *temp = head;
        while(l1 || l2){
            int val = ((l1) ? l1->val : 0)  + ((l2) ? l2->val : 0) + carry ; 
            if(val > 9){
                carry = val/10;
                val = val%10;
            }else{
                carry = 0 ;
            }
            
            temp->next = new ListNode(val);
            temp = temp->next;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }
        
        if(carry > 0) temp->next = new ListNode(carry);
        return head->next;
    }
};