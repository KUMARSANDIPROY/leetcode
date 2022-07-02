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
    Node *reverse(Node *head)
    {
        if(head==NULL || head->next==NULL) return head;
        
        Node *pre=NULL,*cur=head,*post=NULL;
        
        while(cur)
        {
            post=cur->next;
            cur->next=pre;
            pre=cur;
            cur=post;
        }
        return pre;
    }
    
    Node *compute(Node *head)
    {
        // your code goes here
        Node *head1=reverse(head);
         int mx=head1->data;
        Node* temp=head1->next,*prev=head1;
         
        while(temp)
        {
            if(temp->data >= mx)
            {
                mx=temp->data;
                prev=temp;
                temp=temp->next;
                
            }
            else if(temp->data < mx)
            {
                prev->next=temp->next;
                temp=temp->next;
            }
        }
        Node *res_head=reverse(head1);
        return res_head;
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