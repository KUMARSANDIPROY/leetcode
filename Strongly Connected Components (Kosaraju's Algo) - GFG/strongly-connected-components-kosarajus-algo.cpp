// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	void dfs1(vector<int> adj[],vector<int> &visited1,int node,stack<int> &st)
	{
	    visited1[node]=1;
	    for(int i:adj[node])
	    {
	        if(visited1[i]==0)
	           dfs1(adj,visited1,i,st);
	    }
	   
	    st.push(node);
	}
		void dfs2(vector<int> adj[],vector<int> &visited2,int node)
	{
	    visited2[node]=1;
	    for(int i:adj[node])
	    {
	        if(visited2[i]==0)
	           dfs2(adj,visited2,i);
	    }
	    
	}
	
	
    int kosaraju(int V, vector<int> adj[])
    {
        //code here
    vector<int> rev_adj[V];
    vector<int> visited1(V,0);
    vector<int> visited2(V,0);
    stack<int> st;
    
    for(int i=0;i<V;i++)
    {
        if(visited1[i]==0)
        {
            dfs1(adj,visited1,i,st);
        }
    }
    
    for(int i=0;i<V;i++)
    {
        for(int it:adj[i])
        {
            rev_adj[it].push_back(i);
        }
    }
    
    int count=0;
    
   while(!st.empty())
   {
       int x=st.top();
       st.pop();
       
       if(visited2[x]==0)
         {
               count++;
             dfs2(rev_adj,visited2,x);
           
         }
   }
    return count;
    
    }
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends