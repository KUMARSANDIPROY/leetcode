class Solution {
public:
    bool topo(vector<int> adj[],int n)
    {
        queue<int> q;
        
        vector<int> indegree(n,0);
        
        for(int i=0;i<n;i++)
        {
            for(auto it:adj[i])
            {
                indegree[it]++;
            }
        }
        
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
                q.push(i);
        }
        
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            
            count++;
            for(int it:adj[node])
            {
                indegree[it]--;
                if(indegree[it]==0)
                    q.push(it);
            }
        }
         if(count==n)  return true;
        else  return false;
            
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        int n=numCourses;
        vector<int> adj[n];
        
        for(auto it: prerequisites)
        {
            adj[it[0]].push_back(it[1]);
        }
        
        return topo(adj,n);
        
    }
};