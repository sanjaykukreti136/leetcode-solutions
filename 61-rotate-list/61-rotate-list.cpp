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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode *t = head;
        if(!head || k==0) return head;
        int c= 0;
        while(t){
            t = t->next;
            c++;
        }
        // if(c == 1) 
        if(c == k || c==1) return head;
        // if(k > c) k= k%c;
        while(k>c){
            k= k%c;
        }
        if(k==0) return head;
        c-=k+1;
        t = head;
        while(c--){
            t = t->next;
        }
        // cout<<t->val<<" ";
        ListNode *temp = head;
        head = t->next;
        t->next = NULL;
        ListNode *ans = head;
        
        while(head && head->next){
            head = head->next;
        }
        head->next = temp;
        return ans;
    }
};