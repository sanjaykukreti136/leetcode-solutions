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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *temp = new ListNode(-1);
        temp->next = head;
        ListNode *prev = temp;
        ListNode *curr = head;
        while(curr){
            
            while(curr->next && curr->next->val == prev->next->val){
                curr = curr->next;
            }
            if(prev->next == curr){
                prev = prev->next;
            }
            else{
                prev->next = curr->next;
            }
            curr = curr->next;
            
        }
        return temp->next;
    }
};