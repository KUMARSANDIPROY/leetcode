// { Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//Back-end complete function Template for C++

 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 };

class Solution{
    public:
    TreeNode* solve(TreeNode *&root,int x,TreeNode *&succ)
    {
        if(root==NULL)
        {
            root=new TreeNode(x);
            return root;
        }
        if(x< root->val)
        {
            //cout<<root->val<<"   ";
            succ=root;
            root->left=solve(root->left,x,succ);
            
        }
        else if(x>=root->val)
          root->right=solve(root->right,x,succ);
          
          return root;
        
        
    }
    vector<int> findLeastGreater(vector<int>& arr, int n) {
        
        TreeNode *root=NULL;
        for(int i=n-1;i>=0;i--)
        {
            TreeNode *succ=NULL;
            
            root=solve(root,arr[i],succ);
            if(succ)
            {
                arr[i]=succ->val;
            }
            else
            arr[i]=-1;
        }
        return arr;
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
	    cin >> n;
	    vector<int>arr(n);
	    for(int i = 0 ; i < n; i++){
	        cin >> arr[i];
	    }
	    Solution ob;
	    vector<int> ans = ob.findLeastGreater(arr, n);
	    for(auto it : ans){
	        cout << it << " ";
	    }
	    cout <<endl;
	}
	return 0;
}
  // } Driver Code Ends