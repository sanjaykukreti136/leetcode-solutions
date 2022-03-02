// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}



 // } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
    public:
    Node* reverse(Node* head)
    {
        if(head==NULL or head->next==NULL) return head;
        Node* prev=NULL;
        Node* curr=head;
        Node* nextPtr ;
        
        while(curr!=NULL)
        {
            nextPtr =curr->next;
            curr->next = prev;
            prev=curr;
            curr= nextPtr;
        }
        return prev;
    }
    Node *compute(Node *head)
    {
        // your code goes here
        if(head==NULL or head->next==NULL) return head;
        
        
        Node* rev= reverse(head);
        int maxi = rev->data;
        Node* dummy = new Node(0);
        Node* t=dummy;
        Node* curr=rev;
        
        while(curr!=NULL)
        {
            if(curr->data>=maxi)
            {
                // cout<<curr->data<<" ";
                maxi=curr->data;
                Node* newNode= new Node(curr->data);
                t->next=newNode;
                t=t->next;
            }
            curr=curr->next;
        }
        t->next=NULL;
        // while(dummy){
        //     cout<<dummy->data<<" ";
        //     dummy = dummy->next;
        // }
        dummy = reverse(dummy->next);
        return dummy;
    }
    
};

// { Driver Code Starts.

int main()
{
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}
  // } Driver Code Ends