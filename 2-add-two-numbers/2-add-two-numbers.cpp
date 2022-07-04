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
    
    ListNode *reverse(ListNode *head){
        ListNode *prev = NULL;
        while(head){
            ListNode *t = head->next;
            head->next = prev;
            prev = head;
            head = t;
        }
        return prev;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = NULL;
        ListNode *temp = NULL;
        int c = 0;
        while(l1 && l2){
            int num = l1->val+ l2->val + c;
            if(num > 9){

                c = num/10;
                num = num%10;
            }else{
                c= 0;
            }
            ListNode *newnode = new ListNode(num);
            if(!head){
                head = temp = newnode;
            }else{
                temp->next = newnode;
                temp = newnode;
            }
            l1  = l1->next;
            l2 = l2->next;
        }
        while(l1){
            int num = l1->val + c;
            if(num > 9){
                c = num/10;
                num = num%10;
                
            }else{
                c= 0;
            }
            ListNode *newnode = new ListNode(num);
            if(!head){
                head = temp = newnode;
            }else{
                temp->next = newnode;
                temp = newnode;
            }
            l1 = l1->next;
        }
        while(l2){
            int num =  l2->val + c;
            if(num > 9){
                c = num/10;
                num = num%10;
                // c = num/10;
            }else{
                c= 0;
            }
            ListNode *newnode = new ListNode(num);
            if(!head){
                head = temp = newnode;
            }else{
                temp->next = newnode;
                temp = newnode;
            }
            l2 = l2->next;
        }
        if(c!=0){
            ListNode *newnode = new ListNode(c);
            if(!head){
                head = temp = newnode;
            }else{
                temp->next = newnode;
                temp = newnode;
            }
        }
        return (head);
        
    }
};