// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data <<" "; 
        node = node->next; 
    }  
    cout<<"\n";
} 


 // } Driver Code Ends
//User function template for C++

/*
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution{
public:
    Node* divide(int N, Node *head){
        // code here
        Node *even_head=NULL,*odd_head=NULL,*even_tail=NULL,*odd_tail=NULL;
        
        Node *temp=head;
        while(temp)
        {
            if(temp->data % 2==0)
            {
                if(even_head==NULL )
                {
                    even_head=temp;
                    even_tail=temp;
                   
                }
                else
                   {
                     //  cout<<temp->data<<"e  ";
                       even_tail->next=temp;
                       even_tail=temp;
                   }
               // cout<<temp->data<<"e  ";
               
            }
             else if(temp->data % 2==1)
            {
                if(odd_head==NULL )
                {
                    odd_head=temp;
                    odd_tail=temp;
                   
                }
                else
                   {
                       odd_tail->next=temp;
                       odd_tail=temp;
                   }
                
                
            }
             temp=temp->next;   
            
        }
      //  cout<<even_tail->data<<odd_tail->data<<"hh ";
        if(even_tail)
          even_tail->next=NULL;
        if(odd_tail)
          odd_tail->next=NULL;
          
        if(even_head==NULL)
           return odd_head;
        else
        {
            //cout<<".,kj";
            even_tail->next=odd_head;
            return even_head;
        }
    }
};

// { Driver Code Starts.

int main() {
    //code
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        
        Solution ob;
        Node *ans = ob.divide(N, head);
        printList(ans); 
    }
    return 0;
}
  // } Driver Code Ends