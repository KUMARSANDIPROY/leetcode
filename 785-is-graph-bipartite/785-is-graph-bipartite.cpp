class Solution {
public:
    bool solve(vector<vector<int>> graph,int color[],int node)
    {
        queue<int> q;
        color[node]=0;
        q.push(node);
        while(!q.empty())
        {
            int l=q.size();
            int prev=q.front();
            q.pop();
            for(auto it:graph[prev])
            {
                if(color[it]==-1)
                {
                    color[it]=1-color[prev];
                    q.push(it);
                }
                else if(color[it]!=-1 && color[it]==color[prev])
                    return false;
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int l=graph.size();
        int color[l];
        memset(color,-1,sizeof(color));
        
        for(int i=0;i<l;i++)
        {
            if(color[i]==-1)
                if(solve(graph,color,i)==false)
                    return false;
            
                 
        }
        
        return true;
        
        
    }
};