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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head=NULL;
        ListNode *temp= NULL;
        while(l1 && l2){
            ListNode *newnode;
            if(l1->val < l2->val){
                 newnode= new ListNode(l1->val);
                l1= l1->next;
            }
            else {
                
                newnode= new ListNode(l2->val);
                l2= l2->next;
            }
            if(head==NULL){
                head= temp= newnode;
            }
            else{
                temp->next= newnode;
                temp = newnode;
            }
        }
        while(l1){
             ListNode* newnode= new ListNode(l1->val);
                l1= l1->next;
                if(head==NULL){
                    head= temp = newnode;
                }
                else {
                temp->next= newnode;
                temp = newnode;
                }
           
        }
        while(l2){
          
             ListNode* newnode= new ListNode(l2->val);
                l2= l2->next;
                if(head==NULL){
                    head= temp = newnode;
                }
                else {
                temp->next= newnode;
                temp = newnode;
                }
        }
        return head;
    }
};