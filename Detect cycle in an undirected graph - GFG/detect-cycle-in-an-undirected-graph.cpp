// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool cycle_dfs(vector<int> adj[],vector<int> &vis,vector<int> &dfsvis,int node,vector<int> &parent)
    {
        vis[node]=1;
        dfsvis[node]=1;
       // cout<<node;
        for(auto i:adj[node])
        {
            if(vis[i]==0)
            {
                //cout<<i<<" ";
                parent[i]=node;
                if(cycle_dfs(adj,vis,dfsvis,i,parent)==true)
                   return true;
            }
            else if(vis[i]==1 && dfsvis[i]==1 && parent[node]!=i)
               return true;
        }
        dfsvis[node]=0;
        return false;
        
    }
    
    
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        int n=V;
         vector<int> vis(n,0);
        vector<int> dfsvis(n,0);
         vector<int> parent(n,-1);
        
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
              if(cycle_dfs(adj,vis,dfsvis,i,parent)==true)
                 return true;
        }
        return false;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends