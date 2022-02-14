// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector<int> key(V+1,INT_MAX);
        vector<bool> in_mst(V+1,false);
        vector<int> parent(V+1,-1);
        key[0]=0;
        parent[0]=-1;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > q;
        
        q.push({0,0});
        
       while(!q.empty())
        {
            int node=q.top().second;
            int d=q.top().first;
            q.pop();
            in_mst[node]=true;
            for(vector<int> it:adj[node])
            {
                if(in_mst[it[0]]==false && key[it[0]]>it[1])
                {
               
                    key[it[0]]=it[1];
                    parent[it[0]]=node;
                     q.push({key[it[0]],it[0]});
                }
            }
            
            
        }
        int res=0;
        for(int i=0;i<V;i++)
        {
            res+=key[i];
        }
         return res;
        
        
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends