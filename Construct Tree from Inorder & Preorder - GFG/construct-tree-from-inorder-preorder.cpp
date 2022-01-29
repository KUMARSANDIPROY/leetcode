// { Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

 // } Driver Code Ends


/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    int idx=0;
    unordered_map<int,int> mp;
    Node* solve(int in[],int pre[],int lf,int rt)
    {
        if(lf>rt)
           return NULL;
        Node *res=new Node(pre[idx++]);
        res->left=res->right=NULL;
        if(lf==rt) return res;  
        else
        {
            int mid=mp[res->data];
             res->left=solve(in,pre,lf,mid-1);
             res->right=solve(in,pre,mid+1,rt);
        }
        return res;
    }
    
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        for(int i=0;i<n;i++)
        {
            mp[in[i]]=i;
        }
        Node *root=solve(in,pre,0,n-1);
        return root;
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}
  // } Driver Code Ends