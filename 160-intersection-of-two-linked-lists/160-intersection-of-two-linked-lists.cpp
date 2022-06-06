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
    int size(ListNode *h){
        int c=0;
        while(h){
            c++;
            h = h->next;
        }
        return c;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
             unordered_map<ListNode*, int> m ;  //create an unordered map storing addresses of the nodes of the Linked Lists
        while(headA != NULL)      //scan 1st linked list by incrementing the counter in the map
        {
            m[headA]++ ;                      //add the address of the node and increment the count by 1 ;
            headA=headA->next ;
        }
        while(headB != NULL)    //scan the 2nd linked list by finding the address with the count value in the map greater than 0
        {
            if(m[headB]>0)    
                return headB ;     // returns intersecting node
            else headB=headB->next ;
        }
        
        return NULL ; 
    }
};