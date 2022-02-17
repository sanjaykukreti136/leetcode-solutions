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
    ListNode* swapPairs(ListNode* head) {
        if(head && head->next){
            ListNode *ans = head->next;
            ListNode *curr = head->next;
            ListNode *prev = head;
            while(curr && prev){
                
                ListNode *temp = curr->next;
                curr->next = prev;
                if(temp){
                    curr = temp->next;
                }else{
                    curr = NULL;
                }
                if(curr){
                prev->next = curr;
                prev = temp;
                }
                else{
                    prev->next = temp;
                    prev = NULL;
                }

                
            }
            return ans;
        }
        else{
            return head;
        }
    }
};