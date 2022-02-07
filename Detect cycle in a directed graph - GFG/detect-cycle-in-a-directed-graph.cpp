// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool cycle_dfs(vector<int> adj[],vector<int> &vis,vector<int> &dfsvis,int node)
    {
        vis[node]=1;
        dfsvis[node]=1;
        
        for(auto i:adj[node])
        {
            if(vis[i]==0)
            {
                if(cycle_dfs(adj,vis,dfsvis,i)==true)
                   return true;
            }
            else if(vis[i]==1 && dfsvis[i]==1)
               return true;
        }
        dfsvis[node]=0;
        return false;
        
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> vis(V,0);
        vector<int> dfsvis(V,0);
        
        for(int i=0;i<V;i++)
        {
            if(vis[i]==0)
              if(cycle_dfs(adj,vis,dfsvis,i)==true)
                 return true;
        }
        return false;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends