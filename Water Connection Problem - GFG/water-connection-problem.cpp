// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    void dfs(pair<int,int> adj[],int start,int &end,int &mn,vector<int> &vis,vector<int> out)
    {
        vis[start]=1;
        if(out[start]==0) return;
        end=adj[start].first;
       // cout<<end<<"end  ";
        mn=min(mn,adj[start].second);
        if(vis[end]==0)
           dfs(adj,adj[start].first,end,mn,vis,out);
    }
    
    vector<vector<int>> solve(int n,int p,vector<int> a,vector<int> b,vector<int> d)
    {
        // code here
        vector<int> in(n+1,0);
        vector<int> out(n+1,0);
        vector<int> vis(n+1,0);
       // vector<pair<int,int>> adj[n+1];
        pair<int,int> adj[n+1];
        vector<vector<int>> res;
        
        for(int i=0;i<p;i++)
        {
            out[a[i]]=1;
            in[b[i]]=1;
            adj[a[i]]={make_pair(b[i],d[i])};
        }
        
        for(int i=1;i<=n;i++)
        {
            if(in[i]==0 && out[i]==1 && vis[i]==0)
            {  // cout<<i<<"strat  ";                                                             
                int start=i;
                int end;
                int mn=INT_MAX;
                dfs(adj,start,end,mn,vis,out);
                
                res.push_back({start,end,mn});
               // cout<<endl;
            }
        }
        
        return res;
    }
};


// { Driver Code Starts.
int main()
{
	int t,n,p;
	cin>>t;
	while(t--)
    {
        cin>>n>>p;
        vector<int> a(p),b(p),d(p);
        for(int i=0;i<p;i++){
            cin>>a[i]>>b[i]>>d[i];
        }
        Solution obj;
        vector<vector<int>> answer = obj.solve(n,p,a,b,d);
        cout<<answer.size()<<endl;
        for(auto i:answer)
        {
            cout<<i[0]<<" "<<i[1]<<" "<<i[2]<<endl;
        }
        
    }
	return 0;
}  // } Driver Code Ends