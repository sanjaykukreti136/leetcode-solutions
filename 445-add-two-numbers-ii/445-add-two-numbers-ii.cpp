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
    
    ListNode *addTwoDigits(ListNode *l1 , ListNode *l2 , int &carry){
        if(!l2 && !l1) return NULL;
        ListNode *curr;
        ListNode *newnode = addTwoDigits(l1->next , l2->next , carry);
        int v = carry + (l1!=NULL ? l1->val : 0) + (l2!=NULL ? l2->val : 0);
        carry = v/10;
        v = v%10;
        curr= new ListNode(v);
        curr->next = newnode;
        return curr;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *curr1 = l1;
        ListNode *curr2 = l2;
        while(curr1 || curr2){
            
            if(curr1 == NULL){
                ListNode *newnode = new ListNode(0);
                newnode->next = l1;
                l1 =newnode;
                curr2 = curr2->next;
            }
            else if(curr2==NULL){
                ListNode *newnode = new ListNode(0);
                newnode->next = l2;
                l2 =newnode;
                curr1 = curr1->next;                
            }else{
                curr1 = curr1->next;
                curr2 = curr2->next;
            }
            
        }
        ListNode *res = new ListNode(-1);
        ListNode *temp = res;
        int carry = 0;
        res =  addTwoDigits(l1 , l2 , carry);
        if(carry){
            ListNode *newnode = new ListNode(1);
            newnode->next = res;
            return newnode;
        }
        return res;
    }
};