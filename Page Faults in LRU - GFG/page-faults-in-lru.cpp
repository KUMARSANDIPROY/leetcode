// { Driver Code Starts
// Initial Template for C++



#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    struct Node
    {
        int data;
        Node *next=NULL;
        
        Node(int key)
        {
            data=key;
            next=NULL;
        }
    };
    
    Node* delete_present_node(Node *head,int key)
    {
        Node *temp=head;
        Node *prev=head;
        if(head==NULL)
        {
            cout<<" ERROR";
            return NULL;
        }
           
        if(head->data==key)
        {
            head=head->next;
            return head;
        }
        
        else
        {
            while(temp && temp->data!=key)
            {
                prev=temp;
                temp=temp->next;
            }
        }
        prev->next=temp->next;
        return head;
    }
    
    Node* remove_least(Node* head)
    {
        if(head==NULL) return head;
        head=head->next;
        return head;
    }
    
    Node* add_node(Node *head,int key)
    {
        Node *node=new Node(key);
        Node *temp=head;
        if(head==NULL)
        {
            head=node;
            return head;
            
        }
           
        
        while(temp->next)
        {
            temp=temp->next;
        }
        temp->next=node;
        return head;
    }
    

    
    int pageFaults(int N, int C, int pages[]){
        // code here

        int res=0;
        Node *head=NULL;
        
        unordered_set<int> s;
        
        for(int i=0;i<N;i++)
        {
            int key=pages[i];
            if(s.find(key)==s.end())
            {
                res++;
                if(s.size()==C)
                {
                    auto x=s.find(head->data);
                    s.erase(x);
                
                    head=remove_least(head);
                
                    
                }
                head=add_node(head,key);
                s.insert(key);
            }
            
            else
            {
                head=delete_present_node(head,key);
                head=add_node(head,key);
                auto it=s.find(key);
               // s.erase(it);
            }
           // cout<<i<<" "<<key<<" "<<res<<endl;
        //   if(i==3)
        //   {
        //       for(int p:s)
        //          cout<<p<<" ";
        //   }cout<<endl;
               
        }
        
        
       return res; 
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, C;
        cin>>N;
        int pages[N];
        for(int i = 0;i < N;i++)
            cin>>pages[i];
        cin>>C;
        
        Solution ob;
        cout<<ob.pageFaults(N, C, pages)<<"\n";
    }
    return 0;
}  // } Driver Code Ends