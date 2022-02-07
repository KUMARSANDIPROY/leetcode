class Solution {
public:                                                    
    bool dfs(vector<vector<int>> graph,vector<int> &color,int node)
    {
       
        
        for(auto it:graph[node])
        {
           if(color[it]==-1)
           {
               color[it]=1-color[node];
              if(dfs(graph,color,it)==false)
                  return false;
           }
            else if(color[it]!=1)
            {
                if(color[it]==color[node])
                    return false;
                
            }
        }
      return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size(),-1);
       // vector<int> parent(graph.size(),-1);
        for(int i=0;i<graph.size();i++)
        {
            if(color[i]==-1)
                if(dfs(graph,color,i)==false)
                    return false;
        } 
        return true;
    }
};