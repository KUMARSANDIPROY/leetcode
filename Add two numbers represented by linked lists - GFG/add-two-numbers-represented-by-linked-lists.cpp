// { Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


 // } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    Node* reverse1(Node* node)
    {
        if(node==NULL || node->next==NULL)
           return node;
           
        Node *prev=NULL,*cur=node,*post=NULL;
        
        while(cur)
        {
            post=cur->next;
            cur->next=prev;
            prev=cur;
            cur=post;
        }
        return prev;
    }
    
    
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        Node* head1=reverse1(first);
        Node* head2=reverse1(second);
        
        Node *temp1=head1,*temp2=head2;
        int carry=0;
        Node *res_head=NULL,*temp3;
        
        while(temp1 && temp2)
        {
           
            int sum=temp1->data + temp2->data + carry;
            Node* temp4=new Node(sum%10);
            carry=sum/10;
            if(res_head==NULL)
            {
                res_head=temp4;
                temp3=res_head;
            }
            else
               {
                   temp3->next=temp4;
                   temp3=temp4;
               }
            temp1=temp1->next;
            temp2=temp2->next;
        }
        
        while(temp1)
        { 
            int sum=temp1->data + carry;
            Node* temp4=new Node(sum%10);
            temp3->next=temp4;
            carry=sum/10;
            
            temp1=temp1->next;
            temp3=temp4;
        }
        
        while(temp2)
        { 
            int sum=temp2->data + carry;
            Node* temp4=new Node(sum%10);
            temp3->next=temp4;
            carry=sum/10;
            temp2=temp2->next;
            temp3=temp4;
        }
        if(carry==1)
        {
            Node *c=new Node(1);
            temp3->next=c;
        }
        
        return reverse1(res_head);
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}
  // } Driver Code Ends