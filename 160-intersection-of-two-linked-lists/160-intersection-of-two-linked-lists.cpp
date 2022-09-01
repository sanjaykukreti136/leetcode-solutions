/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    
    
    ListNode *detect(ListNode *head){
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast->next && fast->next->next){
            fast = fast->next->next;
            slow = slow->next;
            if(slow==fast){
                slow = head;
                while(slow!=fast){
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return NULL;
    }
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB) return NULL;
        if(headA == headB) return headA;
        ListNode *temp= headA;
        while(temp->next){
            temp = temp->next;
        }
        temp->next = headB;
        
        ListNode *ans =  detect(headA);
        temp->next = NULL;
        return ans; 
        
    }
};