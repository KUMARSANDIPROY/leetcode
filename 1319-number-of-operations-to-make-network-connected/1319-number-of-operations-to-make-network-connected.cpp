class Solution {
public:
    void dfs(vector<int> adj[],vector<bool> &visited,int &c,int x)
    {
        visited[x]=true;
        for(int i:adj[x])
        {
            if(!visited[i])
                dfs(adj,visited,c,i);
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) 
    {
        vector<int> adj[n];
        if(connections.size()<n-1) return -1;
        
        for(int i=0;i<connections.size();i++)
        {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        int c=0;//this will count the number of components
        vector<bool> visited(n,false);
        for(int i=0;i<n;i++)
        {
            if(visited[i]==false)
            {
                dfs(adj,visited,c,i);
                c++;  
            }
        }
        return c-1;//number of edges required is 1 less than no components
            
    }
};