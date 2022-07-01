// { Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};




 // } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution{
  public:
    Node* reverse(Node *node)
    {
        if(node==NULL || node->next==NULL) return node;
        
        Node *pre=NULL,*cur=node,*post=NULL;
        
        while(cur)
        {
            post=cur->next;
            cur->next=pre;
            pre=cur;
            cur=post;
        }
        return pre;
    }
  
    Node *middle(Node *head)
    {
        if(head==NULL || head->next==NULL) return head;
        
        Node *slow=head,*fast=head->next;
        
        while(fast && fast->next)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        //Your code here
        Node *mid=middle(head);
       // cout<<mid->data<<endl;
        Node *rev=reverse(mid->next);
       // Node * rev=NULL;
       //cout<<rev->data<<endl;
        
        while(rev)
        {
            
            if(rev->data!=head->data) break;
          // cout<<"jbvkj";
            rev=rev->next;
            head=head->next;
        }
        if(rev==NULL)
           return true;
        
        return false;   
    }
};



// { Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}

  // } Driver Code Ends