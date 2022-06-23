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
        if(!head) return NULL;
        ListNode *first = head;
        ListNode *second = head->next;
        if(second == NULL) return head;
        ListNode *ans = second;
        while(first && second){
            ListNode *second_next = second->next;
            ListNode *first_next = first->next;
            first->next = NULL;
            second->next = first;
            if(second_next && second_next->next) first->next = second_next->next;
            else if(second_next) first->next = second_next;
            else break;
            first = second_next;
            second = first->next;
        }
        
        return ans;
    }
};