// { Driver Code Starts
// C++ program to merge k sorted arrays of size n each
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

/* Function to print nodes in a given linked list */
void printList(Node* node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	cout<<endl;
}

 // } Driver Code Ends
/*Linked list Node structure

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

class Solution{
  public:
    //Function to merge K sorted linked list.
    Node * mergeKLists(Node *arr[], int K)
    {
           // Your code here
           vector<Node*> index(K,NULL);
           Node *head=NULL,*temp;
           
           priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
           
           for(int i=0;i<K;i++)
           {
               index[i]=arr[i];
           }
           
           for(int i=0;i<K;i++)
           {
               q.push({arr[i]->data,i});
           }
           //cout<<q.size();
           while(!q.empty())
           {
               Node *node=new Node(q.top().first);
               int l_no=q.top().second;
             
               q.pop();
               
               if(head==NULL)
               {
                  // cout<<"jn";
                    
                   head=node;
                   temp=head;
               }
               else
               {
                   
                   temp->next=node;
                   temp=temp->next;
               }
               index[l_no]=index[l_no]->next;
               
               if(index[l_no]!=NULL)
               {
                   q.push({index[l_no]->data,l_no});
               }
               
           }
           return head;
    }
};



// { Driver Code Starts.
// Driver program to test above functions
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
	   int N;
	   cin>>N;
       struct Node *arr[N];
       for(int j=0;j<N;j++)
        {
           int n;
           cin>>n;

           int x;
           cin>>x;
           arr[j]=new Node(x);
           Node *curr = arr[j];
           n--;

           for(int i=0;i<n;i++)
           {
               cin>>x;
               Node *temp = new Node(x);
               curr->next =temp;
               curr=temp;
           }
   		}
   		Solution obj;
   		Node *res = obj.mergeKLists(arr,N);
		printList(res);

   }

	return 0;
}
  // } Driver Code Ends