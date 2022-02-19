// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    // Code here
	    vector<int> adj[N];
	    
	    int pre=prerequisites.size();
	    
	    for(int i=0;i<pre;i++)
	    {
	        int x=prerequisites[i].first;
	        int y=prerequisites[i].second;
	        adj[y].push_back(x);
	        
	    }
	    vector<int> indegree(N,0);
	    for(int i=0;i<N;i++)
	    {
	        for(int j:adj[i])
	           indegree[j]++;
	           
	    }
	    
	    queue<int> q;
	    for(int i=0;i<N;i++)
	    {
	        if(indegree[i]==0)
	          q.push(i);
	    }
	    vector<int> res;
	    while(!q.empty())
	    {
	        int x=q.front();
	        q.pop();
	        res.push_back(x);
	        for(int i:adj[x])
	        {
	            indegree[i]--;
	            if(indegree[i]==0)
	              q.push(i);
	        }
	    }
	    
	    return res.size()==N;
	    
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}  // } Driver Code Ends