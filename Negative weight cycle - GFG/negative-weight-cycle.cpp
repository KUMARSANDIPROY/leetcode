// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    // Code here
	    vector<int> dist(n,10000000);
	    dist[0]=0;
	    for(int k=1;k<=n-1;k++)
	    {
	        for(int i=0;i<edges.size();i++)
    	    {
    	        int u=edges[i][0];
    	        int v=edges[i][1];
    	        int d=edges[i][2];
    	        
    	        if(dist[v]>dist[u]+d)
    	        {
    	            dist[v]=dist[u]+d;
    	        }
    	    }
	    }
	    
	    int flag=0;
	     for(int i=0;i<edges.size();i++)
    	 {
    	        int u=edges[i][0];
    	        int v=edges[i][1];
    	        int d=edges[i][2];
    	        
    	        if(dist[v]>dist[u]+d)
    	        {
    	            //dist[v]=dist[u]+d;
    	            flag=1;
    	            break;
    	            
    	        }
    	    }
	    return flag==1;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int x, y, z;
			cin >> x >> y >> z;
			edges.push_back({x,y,z});
		}
		Solution obj;
		int ans = obj.isNegativeWeightCycle(n, edges);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends