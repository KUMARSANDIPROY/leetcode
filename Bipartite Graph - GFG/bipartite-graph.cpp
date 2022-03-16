// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    queue<int> q;
	    vector<int> color(V,-1);
	    vector<int> visited(V,0);
	   
	   for(int i=0;i<V;i++)
	   {
    	    if(visited[i]==0)
    	    {
        	    q.push(i);
        	    color[i]=0;
        	    visited[i]=1;
        	    
        	    while(!q.empty())
        	    {
        	  
        	            int node=q.front();
        	            q.pop();
        	            for(auto it:adj[node])
        	            {
        	                if(color[it]==-1)
        	                {
        	                    color[it]=1-color[node];
        	                    visited[it]=1;
        	                    q.push(it);
        	                }
        	                else if(color[it]==color[node] )
        	                   return false;
        	            }
        	        
        	    }
	         }   
	   }
	    return true;
	    
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}  // } Driver Code Ends